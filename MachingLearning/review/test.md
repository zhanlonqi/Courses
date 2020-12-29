# GAMES102 ѧϰ���� (1)

> ���ߣ�ʷ��� ([syc0412@mail.ustc.edu.cn](mailto:syc0412@mail.ustc.edu.cn))

[TOC]

## 1. ������ֵ

�����ʵ�������У�ĳ������ $f(x)$ �����ܸ��ӡ�û�н���������δ֪����������ֻ��ͨ��ĳЩ�ֶι۲⵽��ӳ�ú�����һЩ�������ݡ�����ϣ��ͨ����Щ�۲�Ĳ������������Ƹú�������Ϣ����Ԥ�⺯���������۲���ֵ����ʱ�����Ǵӹ۲����������һ������ $\phi(x)$ ������ $f(x)$ ��

**����**�� $f(x)$ Ϊ���������� $[a,b]$ �ϵĺ����� $x_0,x_1,\cdots,x_n$ Ϊ������ $n+1$ ��������ͬ�ĵ㣬 $\Phi$ Ϊ������ĳһ�����ࡣ�� $\Phi$ �ϵĺ��� $\phi(x)$ �����㣺
$$
\phi(x_i)=f(x_i), \ \ i=0,1,\cdots,n
$$
��� $\phi(x)$ Ϊ $f(x)$ ���ڽڵ� $x_0,x_1,\cdots,x_n$ �� $\Phi$ �ϵĲ�ֵ�������� $x_0,x_1,\cdots,x_n$ Ϊ��ֵ�ڵ㣬�� $(x_i,f(x_i))$ Ϊ��ֵ�㡣

### 1.1 ����ʽ��ֵ����

**����**���� $x_i$ ������ͬ�������������� $y_i$ ������Ψһ�Ĵ��������� $n$ �εĶ���ʽ $p_n$ ��ʹ�� $p_n(x_i)=y_i��i=0,\cdots,n$ ��

֤�������ݻ� $\lbrace 1,x,\cdots,x^n \rbrace $ �´�������ʽ $p$ ����ʽΪ��

$$
p(x)=a_0+a_1x+a_2 x^2+\cdots+a_n x^n
$$

�ɲ�ֵ���� $p(x_i)=y_i,i=0,\cdots,n$ ���õ����·����飺

$$
\left( \begin{array} {c} 1 &x _ 0 &x _ 0^2 &\dots &x _ o^n \newline 1 &x _ 1 &x _ 1^2 &\dots &x _ 1^n \newline 1 &x _ 2 &x _ 2^2 &\dots &x _ 2^n \newline \vdots &\vdots &\vdots &\ddots &\vdots\newline 1 &x _ n &x _ n^2 &\dots &x _ n^n \newline \end{array} \right) \left( \begin{array} {c} a _ 0 \newline a _ 1 \newline a _ 2 \newline \vdots \newline a _ n \end{array} \right) = \left( \begin{array} {c} y _ 0 \newline y _ 1 \newline y _ 2 \newline \vdots \newline y _ n \end{array} \right)
$$

ϵ������Ϊ **Vandermonde** ����������ʽ���㣬��˷�������Ψһ�⡣

### 1.2 ��ͬ��ʽ�Ĳ�ֵ����ʽ

���ڸ������⣬��ֵ����ʽ����Ψһ�����ǿ����ò�ͬ�ķ���������ֵ����ʽ�Ĳ�ͬ��ʾ��ʽ��

#### 1.2.1 Lagrange��ֵ

**Lagrange������**���ɶ���ʽ��ֵ������ں��� $l_i(x)$ ���� $l_i(x_j)=\sigma_{ij}$ ��

$$
l_i(x)=\prod_{j=0,j\neq i}\frac{x-x_j}{x_i-x_j}
$$

Lagrange��ֵ����ʽ��

$$
L_n(x)=\sum_{k=0}^n y_k l_k(x)
$$

#### 1.2.2 Newton��ֵ

**����**��

һ�ײ��̣�

$$
f[x_0,x_1]=\frac{f(x_1)-f(x_0)}{x_1-x_0}
$$

$k $�ײ��̣�

��$ \lbrace x_0,x_1,\cdots,x_k \rbrace  $������ͬ��$ f(x) $����$ \lbrace x_0,x_1,\cdots,x_k \rbrace  $��$ k $�ײ���Ϊ��

$$
f[x_0,x_1,\cdots,x_k]=\frac{f[x_1,\cdots,x_k]-f[x_0,x_1,\cdots,x_{k-1}]}{x_k-x_0}
$$

����**Newton��ֵ����ʽ**��ʾΪ��

$$
N _ n(x)=f(x _ 0)+f[x _ 0,x _ 1](x-x _ 0)+\cdots+f[x _ 0,x _ 1,\cdots,x _ n](x-x _ 0)\cdots(x-x _ {n-1})
$$

## 2. �������

���������ָ������һ����ɢ�ĵ㣬��Ҫȷ��һ���������ƽ�ԭ������������ɢ����ͨ�����ɹ۲����Եõ��ģ����Բ��ɱ���Ļ�����������Ҫ�ıƽ�ԭ�������ֶ�Ҫ������������������

- ��Ҫ������еĵ㣨�����������Ӱ�죩
- �����ܱ������ݵ����ƣ�������Щ��

����ѧ��������˵���ǣ���Ҫ�ڸ����ĺ����ռ� $\Phi$ ���ҵ����� $\phi$ ��ʹ�� $\phi$ ��ԭ���� $f$ �ľ�����С������ľ���ָ����ĳ�ֶ�������ͬ�Ķ�����Ӧ�Ų�ͬ����Ϸ��������� $\phi(x)$ ��Ϊ $f(x)$ �ڿռ� $\Phi$ �ϵ�������ߡ�

### 2.1 ������ϵ���С���˷�����

**����**�� $f(x)$ Ϊ������ȥ���� $[a,b]$ �ϵĺ����� $\lbrace x _ i \rbrace  _ {i=0}^m$ Ϊ������ $m+1$ ��������ͬ�ĵ㣬 $\Phi$ Ϊ������ĳһ�����ࡣ�� $\Phi$ �ϵĺ��� $\phi(x)$ ���� $f(x)$ �� $\phi(x)$ �ڸ����� $m+1$ �����ϵľ�����С��������־���ȡΪ2-�����Ļ������Ϊ��С�������⡣������ $\phi(x) \in \Phi$ ��ʹ�ã�

$$
R_2=\sqrt{\sum_{i=0}^m (\phi(x_i)-f(x_i))^2}
$$

��С��

#### 2.1.1 ��С������������

���ȸ���������ɢ�ڻ�����ɢ�����Ķ��壺

**����**������ $f,g$ �Ĺ�����ɢ���� $\lbrace x _ i \rbrace  _ {i=0}^m$ ����ɢ�ڻ�Ϊ��
$$
(f,g) _ h=\sum _ {i=0}^n f(x _ i)g(x _ i)
$$

**����**������ $f$ ����ɢ����Ϊ��
$$
||f||_h=\sqrt{(f,f)_h}
$$

�����ڻ��£������Ķ�����������2����һ�¡�

> ���������е��±� $h$ ��ʾ����ɢ�ڻ�����ɢ������ָ��������1-�����Ķ��� $||x|| _ 1=\sum _ {i=1}^n |x _ i|$ �����������⺬�塣

�� $\Phi=span\lbrace \phi_0,\phi_1,\cdots,\phi_n \rbrace $

$$
\phi(x)=a_0\phi_0(x)+a_1\phi_1(x)+\cdots+a_n\phi_n(x)
$$

����С��������Ϊ��

$$
||f(x)-(a_0\phi_0(x)+a_1\phi_1(x)+\cdots+a_n\phi_n(x))||_h
$$

����ϵ�� $\lbrace a_0,a_1,\cdots,a_n \rbrace $ ��С

$$
\begin{aligned}
&||f(x)-(a _ 0\phi _ 0(x)+a _ 1\phi _ 1(x)+\cdots+a _ n\phi _ n(x))|| _ h^2 \newline
=& ||f|| _ h^2-2(f,a _ 0\phi _ 0(x)+a _ 1\phi _ 1(x)+\cdots+a _ n\phi _ n(x)) _ h+||a _ 0\phi _ 0(x)+a _ 1\phi _ 1(x)+\cdots+a _ n\phi _ n(x)|| _ h^2 \newline
=&||f|| _ h^2-2\sum _ {k=0}^n a _ k(f,\phi _ k) _ h+\sum _ {i,k=0}^n a _ i a _ k(\phi _ i,\phi _ k) _ h \newline
=&Q(a _ 0,a _ 1,\cdots,a _ n)
\end{aligned}
$$

����������ϵ�� ${a_0,a_1,\cdots,a_n}$ ��С�������

$$
\begin{align*}
&\frac{\partial Q}{\partial a_i}=0 ,\ \ \ i=0,1,\cdots,n \newline
i.e. \ \ &\sum_{k=0}^n a_k(\phi_i,\phi_k)_h=(f,\phi_i)_h,\ \ \ i=0,1,\cdots,n 
\end{align*}
$$

д�ɾ�����ʽ�У�

$$
\left( \begin{array} {c} (\phi _ 0,\phi _ 0) _ h & \dots & (\phi _ 0,\phi _ n) _ h \newline \vdots & \ddots & \vdots \newline (\phi _ n,\phi _ 0) _ h & \dots &(\phi _ n,\phi _ n) _ h \end{array} \right) \left( \begin{array} {c} a _ 0 \newline \vdots \newline a _ n \end{array} \right) = \left( \begin{array} {c} (f,\phi _ 0) _ h\newline \vdots \newline (f,\phi _ n) _ h \end{array} \right)
$$

#### 2.1.2 �������

**��1**��ȡ $\Phi$ Ϊ���Զ���ʽ�ռ䣬�����ռ�Ļ�Ϊ $\lbrace 1,x \rbrace $ ,�������Ϊ $y=a+bx$ ���򷨷���Ϊ��

$$
\left( \begin{array} {c} (1,1) _ h  & (1��x) _ h \newline (x,1) _ h  &(x,x) _ h \end{array} \right) \left( \begin{array} {c} a \newline b \end{array} \right) = \left( \begin{array} {c} (f,1) _ h\newline (f,x) _ h \end{array} \right)
$$

#### 2.1.3 �������

**��2**��ȡ $\Phi$ Ϊ���Զ���ʽ�ռ䣬�����ռ�Ļ�Ϊ $\lbrace 1,x,x^2 \rbrace $ ,�������Ϊ $y=a_0+a_1 x+a_2 x^2$ ���򷨷���Ϊ��

$$
\left( \begin{array} {c} (1,1) _ h  & (1��x) _ h & (1,x^2) _ h\newline (x,1) _ h  &(x,x) _ h &(x,x^2) _ h\newline (x^2,1) _ h  &(x^2,x) _ h &(x^2,x^2) _ h\newline \end{array} \right) \left( \begin{array} {c} a _ 0 \newline a _ 1 \newline a _ 2 \end{array} \right) = \left( \begin{array} {c} (f,1) _ h\newline (f,x) _ h \newline (f,x^2) _ h \end{array} \right)
$$

## 3. Weierstrass ��һ�ƽ�����

**����**���� $f(x)$ �Ǳ����� $[a,b]$ �ϵ���������������ڶ���ʽ���� ${P_n(x)}$ �� $[a,b]$ ��һ�������� $f(x)$ ��Ҳ���Ƕ���������� $\epsilon > 0 $ �����ڶ���ʽ$P(x) $ ��ʹ�ã�

$$
|P(x)-f(x)| < \epsilon
$$

��һ�� $x\in[a,b] $ ������

֤����ʧһ���ԣ���$[a,b] $ Ϊ$[0,1] $��ʹ�ù����Ե�֤����

��$ X $��$ [0,1] $����������$ f(t) $��ȫ�幹�ɵļ��ϣ�$ Y $�Ƕ���ʽȫ�幹�ɵļ��ϣ�����ӳ�䣺

$$
\begin{align*}
B_n: &\ \ X \ \rightarrow \ \ Y \newline
 & f(t) \mapsto B_n(f,x)=\sum_{k=0}^n f(\frac{k}{n})C_n^k x^k (1-x)^{n-k}
\end{align*}
$$

�õ� ${B_n(f,x)}$ �� $B_n(f,x)$ ��ʾ $f\in X$ ��ӳ�� $B_n$ �����µ��������� $x$ Ϊ������ $n$ �ζ���ʽ����Ϊ $f$ �� $n$ �� $\textbf{Bernstein}$ ����ʽ��

����ӳ�� $B_n$ ,���������������������ϵʽ��

1. ������: �������� $f,g\in X$ �� $\alpha,\beta \in R$ ������
   $$
   B_n(\alpha f+\beta g,x)=\alpha B_n(f,x)+\beta B_n(g,x)
   $$

2. ������: �� $f(t)\geq g(t) (t\in[a,b])$ ,��
   $$
   B_n(f,x) \geq B_n(g,x) \ \ \ x\in [a,b]
   $$

3. 
   $$
   \begin{align*}
     &B_n(1,x)=\sum_{k=0}^n C_n^k x^k (1-x)^{n-k}=1 \newline
     &B_n(t,x)=\sum_{k=0}^n \frac{k}{n} C_n^k x^k (1-x)^{n-k}=x \newline
     &B_n(t^2,x)=\sum_{k=0}^n \frac{k^2}{n^2} C_n^k x^k (1-x)^{n-k}=x^2+\frac{x-x^2}{n}
   \end{align*}
   $$

���� $(t-s)^2 $ �� $ B_n $ ӳ���µ���(�� $ s $ Ϊ����)��

$$
\begin{align*}
    B_n((t-s)^2,x)&= B_n(t^2,x)-2sB_n(t,x)+s^2B_n(1,x) \newline
    &=x^2+\frac{x-x^2}{n}-2sx+s^2=(x-s)^2+\frac{x-x^2}{n}
    \end{align*}
$$

���� $\textbf{Cantor}$ ���� $f$ �� $[0,1]$ ��һ�����������Ƕ������������ $\epsilon > 0$ ������ $\delta > 0$ ����һ�� $t,s\in[0,1]$ :

�� $|t-s| < \delta$ ʱ��������

$$
|f(t)-f(s)| < \frac{\epsilon}{2}
$$

�� $|t-s| \geq \delta$ ʱ��������

$$
|f(t)-f(s)| \leq 2M \leq \frac{2M}{\delta^2}(t-s)^2
$$

���Ƕ�һ�� $t,s\in[0,1]$ ,������

$$
|f(t)-f(s)| \leq \frac{\epsilon}{2}+\frac{2M}{\delta^2}(t-s)^2
$$

����

$$
-\frac{\epsilon}{2}-\frac{2M}{\delta^2}(t-s)^2 \leq f(t)-f(s) \leq \frac{\epsilon}{2}+\frac{2M}{\delta^2}(t-s)^2
$$

����ʽ��ˣ��м䣬�Ҷ���ʽ���� $t$ Ϊ������ $s$ Ϊ������������ӳ�� $B_n$ �����µ��񣬵õ���һ�� $x,s\in[0,1]$ ��������

$$
-\frac{\epsilon}{2}-\frac{2M}{\delta^2}[(x-s)^2+\frac{x-x^2}{n}] \leq B_n(f,x)-f(s) \leq \frac{\epsilon}{2}+\frac{2M}{\delta^2}[(x-s)^2+\frac{x-x^2}{n}]
$$

�� $s=x$ ��ע�⵽ $x(1-x) \leq \frac{1}{4}$ �����õ���һ�� $x\in[0,1]$ ��������

$$
|\sum_{k=0}^n f(\frac{k}{n})C_n^k x^k (1-x)^{n-k}-f(x)| \leq \frac{\epsilon}{2}+\frac{M}{2n\delta^2}
$$

ȡ $N=\lceil \frac{M}{\delta^2 \epsilon} \rceil$ ���� $n>N$ ʱ��

$$
|\sum_{k=0}^n f(\frac{k}{n})C_n^k x^k (1-x)^{n-k}-f(x)| < \epsilon
$$

��һ�� $x\in[0,1]$ ������

## 4. Weierstrass �ڶ��ƽ�����

**����**���� $f(x)$ ���� $2\pi$ Ϊ���ڵ�������������������Ƕ���ʽ����һ�������� $f(x)$ ��Ҳ���Ƕ������������ $\epsilon > 0$ ���������Ƕ���ʽ $T(x)$ ��ʹ��:
$$
|T(x)-f(x)| < \epsilon
$$

��һ�� $x\in(-\infty,+\infty)$ ������

��֤��һ������

**����**���� $g(x)$ �� $[0,\pi]$ ����������������� $ \epsilon > 0$ �������������Ƕ���ʽ $T(x)$ ��ʹ�ã�

$$
|T(x)-g(x)| < \epsilon
$$

��һ�� $x\in[0,\pi]$ ������

֤���� $g(\arccos y)$ �� $[-1,1]$ ���������� $\textbf{Weierstrass}$ ��һ�ƽ����������� $\epsilon > 0$ �����ڶ���ʽ $P(y)$ ��ʹ�ã�

$$
|P(y)-g(\arccos y)| < \epsilon
$$

��һ�� $y\in[-1,1]$ ����������

$$
|P(\cos x)-g(x)|< \epsilon
$$

��һ�� $x\in [0,\pi]$ �����������Ǻ��ʽ

$$
\begin{align*}
   &\cos^2x =\frac{1}{2}(1+\cos {2x}), \newline
   &\cos^3x =\frac{1}{4}(3\cos x+\cos{3x}),\newline
   &\cdots,\newline
   &\cos^{2n}x=\frac{1}{2^{2n-1}}(\sum_{k=1}^{n-1} C_{2n}^k \cos{2(n-k)x}+\frac{1}{2}C_{2n}^n),\newline
   &\cos^{2n+1}x=\frac{1}{2^{2n}}\sum_{k=0}^n C_{2n+1}^k \cos{(2n-2k+1)x}\newline
\end{align*}
$$

��֪ $P(\cos x)=T(x)$ ���������Ƕ���ʽ��

**����**���� $g(x)$ ���� $2\pi$ Ϊ���ڵ�����ż�������� $\textbf{Weierstrass}$ �ڶ��ƽ���������������Ƕ���ʽ���������Ƕ���ʽ��

$\textbf{Weierstrass}$ �ڶ��ƽ������֤����

��$ f(x) $����$ 2\pi $Ϊ���ڵ������������

$$
\phi(x)=f(x)+f(-x),\ \psi(x)=[f(x)-f(-x)]\sin x
$$

�� $\phi(x)$ �� $\psi(x)$ ������ $2\pi$ Ϊ���ڵ�����ż���������������ۣ���֪����������� $\epsilon > 0$ �������������Ƕ���ʽ $T_1(x)$ �� $T_2(x)$ ��ʹ�ã�

$$
|\phi(x)-T_1(x)| < \frac{\epsilon}{2},\ |\psi(x)-T_2(x)| < \frac{\epsilon}{2}
$$

��һ�� $x\in(-\infty,+\infty)$ ������

�� $T_3(x)=T_1(x)\sin^2x+T_2(x)\sin x$ �������ɣ�

$$
|\phi(x)\sin^2x-T_1(x)\sin^2x|< \frac{\epsilon}{2},|\psi(x)\sin x-T_2(x)\sin x|< \frac{\epsilon}{2}
$$

�õ���

$$
\begin{equation}
|2f(x)\sin^2x-T_3(x)| < \epsilon \tag{1} 
\end{equation}
$$

��һ�� $x\in(-\infty,+\infty)$ ������������ʽ�� $f(t-\frac{\pi}{2})$ Ҳ����������Ҳ�У�

$$
|2f(t-\frac{\pi}{2})\sin^2t-T_4(t)| < \epsilon
$$

�� $x=t-\frac{\pi}{2}$ ���õ���

$$
\begin{equation}
|2f(x)\cos^2x-T_4(x+\frac{\pi}{2})| < \epsilon  \tag{2} 
\end{equation}
$$

��һ�� $x\in(-\infty,+\infty)$ ������

�� $T_5(x)=\frac{1}{2}[T_3(x)+T_4(x+\frac{\pi}{2})]$ ����� (1) �� (2)���õ���

$$
|f(x)-T_5(x)| < \epsilon
$$

��һ�� $x\in(-\infty,+\infty)$ ������

## 5. ����ռ���걸��

**����**���� $X$ �Ǿ���ռ䣬 $\lbrace x_n \rbrace \subset X$ �� $\lbrace x_n \rbrace $ �� $X$ �еĻ����У���ָ������ $\epsilon > 0$ ������ $N=N(\epsilon)$ ���� $m,n> N$ ʱ���� $\rho(x_m,x_n) < \epsilon$ ��

**����**���� $X$ ���걸����ռ䣬��ָ $X$ �е��κλ����ж������� $X$ �еĵ㡣

**��**�� $C[a,b]$ ������ $\rho(x,y)=\max |x(t)-y(t)|$ ���걸����ռ䡣

## 6. Fourier����

���ȣ����ں����ǿ͹������������˶�����ѧ��������������ڵ���������г�񶯡������񶯡����ߵ���������ĵ����񵴵ȣ������Ա���Ϊ��

$$
f(t)=A\sin(\omega t +\psi)
$$

���� $t$ ��ʾʱ�䣬 $A$ ��ʾ����� $\omega$ Ϊ��Ƶ�ʣ� $\psi$ Ϊ���ࣨ�뿼��ʱ����ԭ��λ���йأ��������Ϊһ����������

Ȼ������������������źŲ������Һ�����ô�򵥣��緽�������ǲ��ȡ����Ǹ���Ҷ�����������ȵĽ������ۡ��У��Ƶ�����һϵ�е����Ǻ��� $ A_n\sin(n\omega t+\psi_n)$֮������ʾ�Ǹ��ϸ��ӵ����ں��� $ f(x)$������

$$
\begin{equation}
f(t)=A_0+\sum_{n=1}^{\infty}A_n \sin(n \omega t+\psi_n) \tag{3}
\end{equation}
$$

�� $\psi_n$ Ϊ������ $A_n$ Ҳ�ǳ����������ʽ���б��Σ�

$$
A_n \sin(n \omega t+\psi_n)=A_n \sin{\psi_n}\cos(n\omega t)+A_n \cos{\psi_n}\sin(n\omega t)
$$

�� $a_n=A_n\cdot \sin{\psi_n}$ ,\ $b_n=A_n \cos{\psi_n} $ �����д (3) Ϊ������ʽ��

$$
\begin{equation}
f(t)=A_0+\sum_{n=1}^{\infty}[a_n\cos(n\omega t)+b_n\sin(n\omega t)]
\end{equation} \tag{4}
$$

���ǳ����� **Fourier** ������ʽ��

### 6.1 ϵ�����

�� (4) ʽ�� $[-\pi,\pi]$ ���֣��ã�

$$
\begin{align*}
\int_{-\pi}^{\pi} f(t) dt &=\int_{-\pi}^{\pi} A_0dt +\int_{-\pi}^{\pi} \sum_{n=1}^{\infty}[a_n\cos(n\omega t)+b_n\sin(n\omega t)] dt \newline
&=\int_{-\pi}^{\pi} A_0 dt+0\newline
&=2\pi A_0
\end{align*}
$$

��ã� $A_0=\frac{1}{2\pi}\int_{-\pi}^{\pi} f(t)$ ��

����������˵�һ��ϵ�� $A_0$ �ı��ʽ���������� $a_n$ �� $b_n$ �ı��ʽ���� $\cos(k\omega t)$ �� (4) ʽ���ߵã�

$$
f(t)\cdot \cos(k\omega t)=A_0 \cos(k\omega t)+\sum_{n=1}^{\infty}[a_n\cos(n\omega t)\cos(k\omega t)+b_n\sin(n\omega t)\cos(k\omega t)]
$$

����ʽ�� $[-\pi,\pi]$ ���֣��ã�

$$
\int_{-\pi}^{\pi}f(t)\cdot \cos(k\omega t) dt=A_0 \int_{-\pi}^{\pi}\cos(k\omega t) dt+\sum_{n=1}^{\infty}[a_n\int_{-\pi}^{\pi}\cos(n\omega t)\cos(k\omega t) dt+b_n\int_{-\pi}^{\pi}\sin(n\omega t)\cos(k\omega t) dt]
$$

�����Ǻ���ϵ�������ԣ� $A_0$ �� $b_n$ ����־�Ϊ0�� $a_n$ ����ֵ��ҽ��� $k=n$ ʱ��Ϊ0�����ԣ�

$$
\begin{align*}
\int_{-\pi}^{\pi}f(t)\cdot \cos(n\omega t) dt&=a_n\ int_{-\pi}^{\pi} \cos^2(n\omega t) dt \newline
&=\frac{a_n}{2}\int_{-\pi}^{\pi}(1+\cos{2n\omega t}) dt \newline
&=\frac{a_n}{2}(\int_{-\pi}^{\pi} 1 dt+\int_{-\pi}^{\pi} \cos{2n\omega t} dt)\newline
&=\frac{a_n}{2} \dot 2\pi =a_n\pi
\end{align*}
$$

��ã�

$$
a_n=\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\cdot \cos(n\omega t) dt
$$

ͬ���� $\sin(k\omega t) $ �� (4) ʽ���ߵã�

$$
b_n=\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\cdot \sin(n\omega t) dt
$$

�� $a_0=2A_0$ ���У�

$$
f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}[a_n\cos(n\omega t)+b_n\sin(n\omega t)]
$$
