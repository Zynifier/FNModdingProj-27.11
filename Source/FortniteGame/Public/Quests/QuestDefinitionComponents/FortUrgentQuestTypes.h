// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortUrgentQuestData.h"
#include "FortUrgentQuestTypes.generated.h"

class UObject;
class USoundBase;

UENUM(BlueprintType)
enum class EDeathFailurePolicy : uint8
{
	None = 0,
	FailQuestIfAnyParticipantDies = 1,
};

USTRUCT(BlueprintType)
struct FUrgentQuestSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	FGameplayTag EventTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="General")
	EDeathFailurePolicy DeathFailurePolicy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Time")
	float TotalEventTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Time")
	bool bQuestCompleteOnTimeExpiration;

	UPROPERTY(EditDefaultsOnly, Category="Presentation")
	bool bDisplayHUDData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	int32 SortPriority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	bool bHideQuestProgressBar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UrgentQuestSettings")
	bool bHideOptionalObjectives;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	bool bReverseProgressBar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	bool bDisplayStartedEventUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation", meta=(AllowedClasses="/Script/Engine.Texture,/Script/Engine.MaterialInterface,/Script/Engine.SlateTextureAtlasInterface", AllowPrivateAccess="true", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Alert Icon", DisplayThumbnail="true"))
	TSoftObjectPtr<UObject> AlertIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Presentation")
	TSoftObjectPtr<USoundBase> SpecialEventStartedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	FLinearColor AlertIconBorderColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	FVector2D AlertIconBrushSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation")
	bool bOverrideWidgetPrimaryColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Presentation", meta=(EditCondition="bOverrideWidgetPrimaryColor"))
	FLinearColor OverriddenWidgetPrimaryColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText EventTitle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText EventSubtitle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText EventSubtitleSecondary;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText EventDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText EventDescriptionGamepad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText EventDescriptionTouch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	TArray<FUrgentQuestDataDescOverrides> EventDescriptionOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Text")
	FText QuestProgressTextFormat;

};

