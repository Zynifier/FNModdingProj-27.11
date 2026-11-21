// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DynamicUI/DynamicUIAdjust.h"
#include "DynamicUI/DynamicUIAllow.h"
#include "DynamicUI/DynamicUIDeprecation.h"
#include "DynamicUIScene.generated.h"

class UDynamicUIUnallowBase;
class UWidget;

USTRUCT()
struct FDynamicUIPreload
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(AllowAbstract="false"))
	TSoftClassPtr<UWidget> Widget;

};

UCLASS(Config=Editor, EditInlineNew, BlueprintType)
class DYNAMICUI_API UDynamicUIScene : public UDataAsset
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(GetOptions="DynamicUI.DynamicUIScene.GetLayerNames"))
	FString Layer;
#endif

	UPROPERTY()
	uint8 LayerID;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(DisplayName="Allow"))
	TArray<FDynamicUIAllowed> Allowed;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI")
	TArray<TObjectPtr<UDynamicUIUnallowBase>> Unallow;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	TArray<FDynamicUIAdjust> Adjust;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	TArray<FDynamicUIPreload> Preload;

private:
#if WITH_EDITOR
	UFUNCTION()
	static TArray<FString> GetLayerNames();
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Config, Transient)
	TMap<FString, uint8> LayerNames;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<FDynamicUIUnallowed> Unallowed;
#endif

};

