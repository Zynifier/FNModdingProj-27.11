// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "FortUrgentQuestData.generated.h"

class AFortPlayerStateAthena;
class UObject;
class USoundBase;
class UTexture2D;

UENUM(BlueprintType)
enum class EObjectiveCategories : uint8
{
	Default = 0,
	Exploration = 1,
	Resource = 2,
	Combat = 3,
	Ranked = 4,
};

USTRUCT(BlueprintType)
struct FUrgentQuestDataDescOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestDataDescOverrides")
	FGameplayTag OverrideTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestDataDescOverrides")
	FText EventDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestDataDescOverrides")
	FText EventDescriptionGamepad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestDataDescOverrides")
	FText EventDescriptionTouch;

};

USTRUCT(BlueprintType)
struct FUrgentQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FGameplayTag EventTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	float TotalEventTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bQuestCompleteOnTimeExpiration;

	UPROPERTY(EditDefaultsOnly, Category="UrgentQuestData")
	bool bDisplayHUDData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText EventTitle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText EventSubtitle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText EventSubtitleSecondary;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText EventDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText EventDescriptionGamepad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText EventDescriptionTouch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	TArray<FUrgentQuestDataDescOverrides> EventDescriptionOverrides;

	UPROPERTY(BlueprintReadWrite, Transient, Category="UrgentQuestData")
	FGameplayTag EventDescriptionOverrideTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	int32 SortPriority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bHideQuestProgressBar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bHideOptionalObjectives;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	FText QuestProgressTextFormat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bReverseProgressBar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bShowBountyThreatInformation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bShowBountyPriceAndDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	bool bDisplayStartedEventUI;

	UPROPERTY(BlueprintReadWrite, Category="UrgentQuestData")
	bool bIsSharedUrgentQuest;

	UPROPERTY(BlueprintReadWrite, Category="UrgentQuestData")
	TObjectPtr<AFortPlayerStateAthena> DisplayPlayer;

	UPROPERTY(BlueprintReadWrite, Category="UrgentQuestData")
	TObjectPtr<AFortPlayerStateAthena> AcceptingPlayer;

	UPROPERTY(BlueprintReadWrite, Category="UrgentQuestData", meta=(DisplayName="Avatar Icon"))
	TSoftObjectPtr<UTexture2D> SocialAvatarBrushPtr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Brush", meta=(AllowedClasses="/Script/Engine.Texture,/Script/Engine.MaterialInterface,/Script/Engine.SlateTextureAtlasInterface", AllowPrivateAccess="true", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Bounty Price Currency Icon", DisplayThumbnail="true"))
	TObjectPtr<UObject> BountyPriceImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Brush", meta=(AllowedClasses="/Script/Engine.Texture,/Script/Engine.MaterialInterface,/Script/Engine.SlateTextureAtlasInterface", AllowPrivateAccess="true", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Alert Icon", DisplayThumbnail="true"))
	TSoftObjectPtr<UObject> AlertIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UrgentQuestData")
	TSoftObjectPtr<USoundBase> SpecialEventStartedSound;

	UPROPERTY()
	FDateTime EventStartTime;

	UPROPERTY()
	FTimerHandle EventTimerHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Brush", meta=(AllowPrivateAccess="true"))
	FLinearColor AlertIconBorderColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Brush", meta=(AllowPrivateAccess="true"))
	FVector2D AlertIconBrushSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Brush")
	bool bOverrideWidgetPrimaryColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Brush", meta=(EditCondition="bOverrideWidgetPrimaryColor"))
	FLinearColor OverriddenWidgetPrimaryColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestData")
	EObjectiveCategories ObjectiveCategory;

};

