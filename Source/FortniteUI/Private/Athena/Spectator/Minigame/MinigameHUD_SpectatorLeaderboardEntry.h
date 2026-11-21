// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "MinigameHUD_SpectatorLeaderboardEntry.generated.h"

class UCommonTextBlock;
class UFortMinigameTeamIdentification;
class UImage;
enum class ESpectatorLeaderboardEntryType : uint8;

UENUM(BlueprintType)
enum class ESpectatorLeaderboardEntryType : uint8
{
	ScoreWithEndScore = 0,
	NoEndScore = 1,
	Time = 2,
	Invalid = 3 UMETA(Hidden),
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UMinigameHUD_SpectatorLeaderboardEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetCoinVisibility(bool bVisible);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayTypeChanged(ESpectatorLeaderboardEntryType EntryType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStandingChanged(int32 Standing, int32 Score);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Standing;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Avatar;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_BackgroundBase;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_BackgroundShape;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_BackgroundShape_Bottom;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Score;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EndScore;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ScoreOnly;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ScoreTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SmallScoreTime;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="0", DisplayName="Team ID Class"))
	TSubclassOf<UFortMinigameTeamIdentification> DesignTime_MinigameTeamIdClass;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="1", DisplayName="Standing"))
	int32 DesignTime_Standing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="0", DisplayName="Score"))
	int32 DesignTime_Score;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="1", DisplayName="End Score"))
	int32 DesignTime_EndScore;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="0", DisplayName="Time (Minutes)"))
	int32 DesignTime_MinutesTime;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMax="59", ClampMin="0", DisplayName="Time (Seconds)"))
	int32 DesignTime_SecondsTime;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMax="99", ClampMin="0", DisplayName="Time (cs)"))
	int32 DesignTime_CsTime;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, DisplayName="Entry Type"))
	ESpectatorLeaderboardEntryType DesignTime_EntryType;
#endif

	UPROPERTY()
	TSubclassOf<UFortMinigameTeamIdentification> CachedMinigameTeamIdClass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MinigameHUD_SpectatorLeaderboardEntry", meta=(AllowPrivateAccess="TRUE"))
	ESpectatorLeaderboardEntryType CachedEntryType;

};

