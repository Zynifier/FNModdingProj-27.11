// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DynamicUI/DynamicUITypes.h"
#include "DynamicUIManager.generated.h"

class APlayerController;
class UDynamicUIScene;
class ULocalPlayer;

UCLASS()
class UDynamicUIManager : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	void AddScene(const UDynamicUIScene* Scene, UPARAM(ref) APlayerController*& Player);

	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	void AddScenes(const TArray<UDynamicUIScene*> Scenes, UPARAM(ref) APlayerController*& Player);

	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	void AddSceneToFirstLocalPlayer(const UDynamicUIScene* Scene);

	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	void RemoveScene(const UDynamicUIScene* Scene, UPARAM(ref) APlayerController*& Player);

	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	void RemoveSceneFromFirstLocalPlayer(const UDynamicUIScene* Scene);

	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	void RemoveScenes(const TArray<UDynamicUIScene*> Scenes, UPARAM(ref) APlayerController*& Player);

private:
	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<ULocalPlayer>, FDynamicUIPlayerData> PlayerDataMap;

};

