public class ByWord{
	public static String reverse(String s){
		String[] words = s.replaceAll("( )+", " ").split(" ");
		String out = "";
		for(int i = words.length - 1; i >= 0; i--) out += words[i] + " ";
		return out;
	}
}
