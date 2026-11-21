// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortItemPresentationDisplayData.generated.h"

class UAthenaGiftReceivedPrompt;
class UFortItemNotification;
class UFortItemPresentationScreen;
class UObject;

UENUM(BlueprintType)
enum class EItemContextAction : uint8
{
	Equip = 0,
	GoToBattlePassRewards = 1,
	GoToBattlePassCustomization = 2,
	GoToSpecialCollection = 3,
	Count = 4 UMETA(Hidden),
};

USTRUCT()
struct FItemPresentationRestrictionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemPresentationRestrictionData")
	FText HeaderText;

	UPROPERTY(EditAnywhere, Category="ItemPresentationRestrictionData", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface", AssetBundles="Menu"))
	TSoftObjectPtr<UObject> Icon;

};

UCLASS()
class UFortItemPresentationDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortItemPresentationDisplayData")
	TMap<FString, FText> HeaderOverrideStrings;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationDisplayData")
	TMap<FString, FText> BodyOverrideStrings;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationDisplayData")
	TMap<FString, FText> ViolatorOverrideStrings;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationDisplayData")
	TMap<FString, FText> SubheaderOverrideStrings;

	UPROPERTY(EditAnywhere, Category="Textures", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> BattlePassUnownedIcon;

	UPROPERTY(EditAnywhere, Category="Textures", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> BattlePassOwnedIcon;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationDisplayData")
	FText DefaultBackgroundMessageText;

	UPROPERTY(EditAnywhere, Category="RestrictionInfo")
	TMap<FGameplayTag, FItemPresentationRestrictionData> TagRestrictionData;

	UPROPERTY(EditAnywhere, Category="ItemContextActions")
	TMap<FString, EItemContextAction> ItemTemplateIdToContextActionMap;

protected:
	UPROPERTY(EditAnywhere, Category="ScreenClasses", meta=(AssetBundles="Menu"))
	TSoftClassPtr<UFortItemPresentationScreen> ItemPresentationScreenClass;

	UPROPERTY(EditAnywhere, Category="ScreenClasses", meta=(AssetBundles="Menu"))
	TSoftClassPtr<UAthenaGiftReceivedPrompt> GiftReceivedPromptClass;

	UPROPERTY(EditAnywhere, Category="ScreenClasses", meta=(AssetBundles="Menu"))
	TSoftClassPtr<UFortItemNotification> ItemNotificationPromptClass;

};

