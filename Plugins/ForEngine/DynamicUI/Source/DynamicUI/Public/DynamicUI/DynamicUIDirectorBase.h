// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicUIDirectorBase.generated.h"

class APlayerController;
class UDynamicUIScene;
class ULocalPlayer;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "ActorTick", "Collision", "Cooking", "DataLayers", "Events", "HLOD", "Input", "LOD", "Physics", "Rendering", "Replication", "WorldPartition"), meta=(ChildCannotTick))
class DYNAMICUI_API ADynamicUIDirectorBase : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Dynamic UI Director")
	void AddScene(const UDynamicUIScene* Scene);

	UFUNCTION(BlueprintPure, Category="Dynamic UI Director")
	ULocalPlayer* GetOwningLocalPlayer() const;

	UFUNCTION(BlueprintPure, Category="Dynamic UI Director")
	APlayerController* GetOwningLocalPlayerController() const;

	UFUNCTION(BlueprintCallable, Category="Dynamic UI Director")
	void RemoveScene(const UDynamicUIScene* Scene);

protected:
	UPROPERTY(EditAnywhere, Category="Dynamic UI Director")
	TArray<TObjectPtr<UDynamicUIScene>> DefaultScenes;

	UPROPERTY(VisibleAnywhere, Category="Dynamic UI Director")
	TWeakObjectPtr<ULocalPlayer> OwningLocalPlayer;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI Director")
	bool bEnabledDuringReplay;

};

