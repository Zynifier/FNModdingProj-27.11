// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "AthenaGoalsPageTabList.generated.h"

class UAthenaMapChallengeCategoryTabButton;
class UCommonButtonBase;
class UFortTabListWidgetBase_Legacy;
class UObject;

USTRUCT(BlueprintType)
struct FGoalsPageCategoryTabData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GoalsPageCategoryTabData", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TObjectPtr<UObject> TabDisplayAsset;

	UPROPERTY(EditAnywhere, Category="GoalsPageCategoryTabData")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="GoalsPageCategoryTabData")
	FGameplayTag IncludeTag;

};

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaGoalsPageTabList : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetTabName(const FText& DisplayName);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList_GoalCategories;

	UPROPERTY(EditAnywhere, Category="AthenaGoalsPageTabList")
	TSubclassOf<UAthenaMapChallengeCategoryTabButton> TabButtonClass;

	UPROPERTY(EditAnywhere, Category="AthenaGoalsPageTabList")
	TArray<FGoalsPageCategoryTabData> GoalTabsData;

	UPROPERTY(EditAnywhere, Category="AthenaGoalsPageTabList", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TObjectPtr<UObject> DefaultTabDisplayAsset;

private:
	UFUNCTION()
	void HandleTabButtonCreated(FName TabId, UCommonButtonBase* TabButton);

	UFUNCTION()
	void HandleTabSelected(FName TabNameId);

};

