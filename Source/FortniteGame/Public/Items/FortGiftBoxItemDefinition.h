// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortSubGameTypes.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortGiftBoxItemDefinition.generated.h"

class UObject;
class USoundBase;
class UUserWidget;

UENUM(BlueprintType)
enum class EFortGiftWrapType : uint8
{
	// Epic is giving a user an item as a makegood, scheduled challenge, etc

	System = 0 UMETA(DisplayName="Epic Item Given"),
	// Giftbox intended as an option for users to send to one another

	UserFree = 1 UMETA(DisplayName="User Giftbox"),
	// selectable by users with an item of this type in their profile (not consumed)

	UserUnlock = 2 UMETA(Hidden),
	// selectable by users with an item of this type in their profile (q=1 is consumed on use)

	UserConsumable = 3 UMETA(Hidden),
	// messaging "gift box" (cannot contain anything)

	Message = 4 UMETA(DisplayName="Custom Message"),
	// Gift box which removes item(s)

	Ungift = 5,
};

USTRUCT()
struct FFortGiftBoxItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemData")
	int32 VaultWorldMaterialIndex;

};

USTRUCT(BlueprintType)
struct FFortItemHeaderInformation
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType)
class UFortGiftBoxItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasHeaderSubWidget() const;

	UFUNCTION(BlueprintPure)
	bool HasPreMessageWidget() const;

	UFUNCTION(BlueprintCallable)
	bool TryLoadHeaderSubWidgetClass(TSubclassOf<UUserWidget>& OutWidgetClass);

	UFUNCTION(BlueprintCallable)
	bool TryLoadPreMessageWidgetClass(TSubclassOf<UUserWidget>& OutWidgetClass);

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	ESubGame RestrictToSubgame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxItemDefinition")
	EFortGiftWrapType GiftWrapType;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	FText ViolatorText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxItemDefinition")
	FText DefaultHeaderText;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	FText SubHeaderText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxItemDefinition")
	FText DefaultBodyText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxItemDefinition", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> ItemDisplayAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGiftBoxItemDefinition")
	int32 SortPriority;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	bool bOnlyGroupWithSameGiftboxDefinition;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	bool bReuseExistingBoxIfPossible;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition", meta=(EditCondition="bReuseExistingBoxIfPossible"))
	bool bIgnoreReuseOptions;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	bool bOverrideBackgroundMessage;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition", meta=(EditCondition="bOverrideBackgroundMessage", MultiLine="true"))
	FText BackgroundMessageText;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	bool bShowInFTUE;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	TSoftClassPtr<UUserWidget> GiftBoxPreMessageWidgetRef;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	TSoftClassPtr<UUserWidget> GiftBoxHeaderSubWidgetRef;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition", meta=(AssetBundles="Menu"))
	TSoftClassPtr<UUserWidget> CustomLeftsideContent;

	UPROPERTY(EditAnywhere, Category="Sound")
	TObjectPtr<USoundBase> GiftBoxActivateSound;

	UPROPERTY(EditAnywhere, Category="Sound")
	TObjectPtr<USoundBase> GiftBoxButtonHoveredOverride;

	UPROPERTY(EditAnywhere, Category="Sound")
	TObjectPtr<USoundBase> GiftBoxButtonPressedOverride;

	UPROPERTY(EditAnywhere, Category="FortGiftBoxItemDefinition")
	FGameplayTag CustomLeftsideContentTag;

	UPROPERTY(EditAnywhere, Category="VaultWorld")
	FGameplayTag VaultWorldOverrideTag;

	UPROPERTY(EditAnywhere, Category="VaultWorld")
	bool bShowVaultWorldPedistals;

	UPROPERTY(EditAnywhere, Category="VaultWorld")
	FFortGiftBoxItemData DefaultItemData;

	UPROPERTY(EditAnywhere, Category="VaultWorld")
	TMap<FString, FFortGiftBoxItemData> ItemOverrideData;

};

