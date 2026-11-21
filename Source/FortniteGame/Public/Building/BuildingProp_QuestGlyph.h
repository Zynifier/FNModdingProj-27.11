// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Building/BuildingProp_Quest.h"
#include "BuildingProp_QuestGlyph.generated.h"

class AFortPlayerController;
class UFortMontageItemDefinitionBase;
class UFortQuestItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_QuestGlyph : public ABuildingProp_Quest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTriggeringEmote(AFortPlayerController* FortPC, const UFortMontageItemDefinitionBase* EmoteAsset, const FGameplayTagContainer& FilteredQuestMetaDataTags);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GlyphParentBlueprint")
	TObjectPtr<UFortQuestItemDefinition> QuestDef;

	UPROPERTY(EditDefaultsOnly, Category="GlyphParentBlueprint")
	FLinearColor InteractSubTextColor;

	UPROPERTY(EditDefaultsOnly, Category="GlyphParentBlueprint")
	FLinearColor InteractSubTextColorUnlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GlyphParentBlueprint")
	bool bShowContextInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GlyphParentBlueprint")
	bool bContextInfoUnlocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GlyphParentBlueprint")
	float ActivationRange;

	UPROPERTY(EditAnywhere, Category="GlyphParentBlueprint")
	TArray<TObjectPtr<UFortMontageItemDefinitionBase>> GlyphActivationEmotes;

};

