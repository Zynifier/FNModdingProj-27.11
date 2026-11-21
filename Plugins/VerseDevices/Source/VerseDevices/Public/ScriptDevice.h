// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/TopLevelAssetPath.h"
#include "Building/BuildingProp.h"
#include "ScriptDevice.generated.h"

class UVerseCreativeDevice;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class VERSEDEVICES_API AScriptDevice : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetVisibility(bool bVisible);

	UFUNCTION()
	void HandlePreMinigameStartedSetup();

protected:
	UFUNCTION(BlueprintCallable)
	void SetEnabled(bool bInEnabled);

	UPROPERTY(EditAnywhere, SaveGame, Instanced, Category="ScriptDevice")
	TObjectPtr<UVerseCreativeDevice> Script;

private:
	UPROPERTY(Transient)
	TObjectPtr<UVerseCreativeDevice> ScriptInstance;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FTopLevelAssetPath ScriptClassPath;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<uint8> ScriptPropertyOverrides;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bIsUsingSoftObjectPathSerialization : 1;
#endif

};

