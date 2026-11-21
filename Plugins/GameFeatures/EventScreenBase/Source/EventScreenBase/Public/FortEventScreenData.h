// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Styling/SlateBrush.h"
#include "Items/ItemPreviewTypes.h"
#include "FortEventScreenData.generated.h"

class UFortChallengeBundleItemDefinition;
class UFortEventMoreInfoModal;
class UFortEventPurchaseLevelsModal;
class UFortEventPurchasePremiumTrackModal;
class UFortItemDefinition;
class UFortTokenType;
class UMaterialInterface;
class URichTextBlockDecorator;
class USoundBase;
class UTexture2D;

USTRUCT(BlueprintType)
struct FEventItemOverride
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="EventItemOverride")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, Category="EventItemOverride")
	TSoftObjectPtr<UTexture2D> CustomItemTexture;

	UPROPERTY(EditAnywhere, Category="EventItemOverride")
	TSoftObjectPtr<UTexture2D> CustomItemTextureMobile;

	UPROPERTY(EditAnywhere, Category="EventItemOverride")
	bool bIsDoubleWidth;

};

USTRUCT(BlueprintType)
struct FEventScreenTrackData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EventScreenTrackData")
	FLinearColor TrackColorPrimary;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EventScreenTrackData")
	FLinearColor TrackColorSecondary;

};

UCLASS(BlueprintType, Blueprintable)
class UFortEventScreenData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CMS")
	FString EventCMSId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Profile")
	FString AccountResourceName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Profile")
	FString LevelOfferId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Profile")
	FString PremiumTrackOfferId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Profile")
	TObjectPtr<UFortTokenType> PremiumTrackPurchasedToken;

	UPROPERTY(EditDefaultsOnly, Category="Vault World", meta=(Categories="UI.ItemPreview.SceneChanger"))
	FGameplayTag VaultWorldTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vault World")
	FVaultWorldBackgroundData PreviewScreenBackgroundData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> QuestBundle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
	TSoftObjectPtr<UFortItemDefinition> SpecialRewardItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
	TSoftObjectPtr<UFortItemDefinition> SpecialPremiumRewardItem;

	UPROPERTY(EditDefaultsOnly, Category="Rewards")
	TArray<FEventItemOverride> ItemOverrides;

	UPROPERTY(EditAnywhere, Category="Tracks")
	FEventScreenTrackData FreeTrackData;

	UPROPERTY(EditAnywhere, Category="Tracks")
	FEventScreenTrackData PremiumTrackData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quests")
	FGameplayTag QuestCategoryTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rich Text")
	TArray<TSubclassOf<URichTextBlockDecorator>> RichTextDecorators;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Brushes")
	UMaterialInterface* EventBackgroundMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Brushes")
	UMaterialInterface* ProgressBarMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Brushes")
	FSlateBrush CurrencyBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Brushes")
	FSlateBrush CompletionBannerBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Brushes")
	FSlateBrush GlowForeground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Brushes")
	FSlateBrush GlowBackground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FLinearColor EventBackgroundColor1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FLinearColor EventBackgroundColor2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FLinearColor RewardBackgroundColor1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FLinearColor RewardBackgroundColor2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FLinearColor RewardBackgroundColor3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FLinearColor AccentColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	TMap<FName, FLinearColor> RewardTileBackgroundColors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Text")
	FText TimeRemainingFormat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Text")
	FText CurrencyFormat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> DefaultHoveredSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> DefaultPressedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> BuyPressedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> BuyHoldStartedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> BuyHoldCompletedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> BuyHoldAbortedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> BackPressedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> AddPressedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> SubtractPressedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> ProgressStartedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> ProgressEndedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	TObjectPtr<USoundBase> ProgressInterruptedSound;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	float RewardPreviewZoomLevel;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	bool bUseWidgetCameraFraming;

	UPROPERTY(EditDefaultsOnly, Category="Modals")
	TSoftClassPtr<UFortEventMoreInfoModal> MoreInfoModalClass;

	UPROPERTY(EditDefaultsOnly, Category="Modals")
	TSoftClassPtr<UFortEventPurchaseLevelsModal> PurchaseLevelsModalClass;

	UPROPERTY(EditDefaultsOnly, Category="Modals")
	TSoftClassPtr<UFortEventPurchasePremiumTrackModal> PurchasePremiumTrackModalClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Events")
	TArray<FString> CalendarEvents;

};

