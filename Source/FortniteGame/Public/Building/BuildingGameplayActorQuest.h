// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorQuest.generated.h"

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorQuest : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetStaticGameplayTags();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Design")
	FGameplayTagContainer QuestActorDefaultTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Design")
	FGameplayTagContainer QuestActorEditorOnlyInstanceTags;
#endif

protected:
	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(DisplayAfter="bSuppressInteractionWidget"))
	uint8 bSuppressSimpleInteractionWidgetForTouch : 1;

};

