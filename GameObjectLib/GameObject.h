#pragma once
#include <iostream>
#include <vector>

class Component {
public:
	Component(const std::string& name) : name(name) {}
	virtual void Update() {
		std::cout << "Mise a jour du composant : " << name << std::endl;
	}
private:
	std::string name;
};

class GameObject
{

private:
	std::string tag;
	std::string name;

	std::vector<Component*> components;

public:
	GameObject(const std::string& tag, const std::string& name) : tag(tag), name(name) {}

	void Update() {
		for (Component* component : components) {
			component->Update();
		}
	}

	void AddComponent(Component* component) {
		components.push_back(component);
	}

	std::string GetName() const {
		return name;
	}

	std::string GetTag() const
	{
		return tag;
	}
	bool HasColliders() const {
		return true;
	}
};