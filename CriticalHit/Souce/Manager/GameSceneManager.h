#pragma once

#include <functional>
#include <memory>
#include <deque>
#include <string>
#include <unordered_map>


class GameScene;

class GameSceneManager final
{
// 名前空間作成
private:
	using ScenePtr			= std::unique_ptr<GameScene>;
	// 両端キュー　Vectorに似てるけど両端からのアクセスか高速にできるクラスです。
	using SceneStack		= std::deque<ScenePtr>;
	// 関数を保持できるクラス？
	using SceneFactory		= std::function<ScenePtr()>;
	using SceneFactoryList	= std::unordered_map<std::string, SceneFactory>;

private:
	SceneFactoryList m_sceneFactories;
	SceneStack		 m_scenes;
	int				 m_popCount;
	std::string		 m_nextSceneName;

private:
	template<typename Scene>
	static ScenePtr CreateScene();

public:
	GameSceneManager();
	~GameSceneManager();

public:
	template<typename Scene>
	// シーンを追加する
	void registerScene(const std::string& sceneName);
	// 一番最初のシーンを設定する
	void SetStartScene(const std::string& sceneName);

	// 更新処理
	void Update(float elapsedTime);
	// 描画処理
	void Render();

	// 次のシーンを要求する
	void RequestScene(const std::string& sceneName);

	void PushScene(const std::string& stateName);

	void PopScene(int counst = 1);

private:
	void ChangeScene();
};

template<typename Scene>
GameSceneManager::ScenePtr GameSceneManager::CreateScene()
{
	// シーンのポインターを作成する。
	return std::make_unique<Scene>();
}

template<typename Scene>
void GameSceneManager::registerScene(const std::string& sceneName)
{
	// ステートのリストへ名前を付けて登録
	m_sceneFactories.insert(std::make_pair(sceneName, CreateScene<Scene>));
}

















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































