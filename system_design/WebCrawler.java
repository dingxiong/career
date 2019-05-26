import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class WebCrawler {
  private static Pattern LINK_PATTERN;
  private static int MAX_COUNT = 100000;

  static {
    String regex = "(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]";
    LINK_PATTERN = Pattern.compile(regex);
  }

  private Set<String> crawl(String startingUrl) {
    Queue<String> que = new LinkedList<>();
    Set<String> visited = new HashSet<>();

    que.offer(startingUrl);
    while (!que.isEmpty() && visited.size() < MAX_COUNT) {
      for (String link: getLinks(que.poll())) {
        if (!visited.contains(link)) {
          que.offer(link);
          visited.add(link);
        }
      }
    }

    return visited;
  }

  static List<String> getLinks(String url) {
    try {
      URL page = new URL(url);
      String content = new BufferedReader(new InputStreamReader(page.openStream()))
          .lines()
          .collect(Collectors.joining("\n"));
      return extractUrlsFromString(content);
    } catch (Exception e) {
      return new ArrayList<>();
    }
  }

  /**
   * Instead of using regex to extract links, we can use some library such as jsoup.
   */
  private static List<String> extractUrlsFromString(String content) {
    List<String> result = new ArrayList<>();
    Matcher m = LINK_PATTERN.matcher(content);
    while (m.find()) {
      result.add(m.group());
    }

    return result;
  }
}
