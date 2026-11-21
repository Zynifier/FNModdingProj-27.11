// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "Athena/Modifiers/Interfaces/InfiltrationRoundInfoMutatorInterface.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Infiltration.generated.h"

class AFortAthenaMutator_RoundHelper;
class AFortAthenaMutator_ShowPlacard;
class AFortPlayerControllerAthena;
class AInfiltrationCarryObjectCapturePoint;
class AInfiltrationCarryObjectSpawnPoint;
class UCurveFloat;
class UGameplayEffect;
class USoundBase;

UENUM(BlueprintType)
enum class EInfiltrationTeam : uint8
{
	Attacking = 0,
	Defending = 1,
	NumOfTeams = 2,
};

UENUM(BlueprintType)
enum class EIntelStateEnum : uint8
{
	None = 0,
	OnGround = 1,
	HeldByAttacker = 2,
	HeldByDefender = 3,
	Downloaded = 4,
	Captured = 5,
	Downloading = 6,
};

USTRUCT()
struct FIconDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="IconDisplayData")
	FSlateBrush MiniMap_Brush;

	UPROPERTY(EditAnywhere, Category="IconDisplayData")
	FSlateBrush Compass_Brush;

	UPROPERTY(EditAnywhere, Category="IconDisplayData")
	FVector2D MapSize;

	UPROPERTY(EditAnywhere, Category="IconDisplayData")
	FVector2D CompassSize;

};

USTRUCT(BlueprintType)
struct FIntelState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	bool bInRange;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	float TimeRemaining;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	float ServerEndTime;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	float ServerGroundTimerEnd;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	EIntelStateEnum IntelState;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	uint8 WinningTeam;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	uint8 AttackingTeam;

	UPROPERTY(BlueprintReadOnly, Category="IntelState")
	uint8 DefendingTeam;

};

USTRUCT(BlueprintType)
struct FInfiltrationModeState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	int32 IntelDownloaded;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	int32 IntelCaptured;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	float TotalTime;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	float TotalGroundTime;

protected:
	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	TArray<FIntelState> IntelStates;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	int32 CurrentRound;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	bool bGameOver;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationModeState")
	FGameplayTag CurrentPOITag;

};

USTRUCT()
struct FInfiltrationPOIInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag POITag;

	UPROPERTY()
	TArray<TObjectPtr<AInfiltrationCarryObjectSpawnPoint>> IntelSpawnPoints;

	UPROPERTY()
	TArray<TObjectPtr<AInfiltrationCarryObjectCapturePoint>> IntelCapturePoints;

	UPROPERTY()
	FText POIOverrideName;

};

USTRUCT(BlueprintType)
struct FInfiltrationTeamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamNum;

	UPROPERTY(VisibleAnywhere, Category="InfiltrationTeamInfo")
	FGameplayTag TeamTag;

};

USTRUCT()
struct FRoundCosmeticInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RoundCosmeticInfo")
	FText RoundNameText;

	UPROPERTY(EditAnywhere, Category="RoundCosmeticInfo")
	TObjectPtr<USoundBase> RoundSound;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Infiltration : public AFortAthenaMutator_GameModeBase, public IInfiltrationRoundInfoMutatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Teams")
	virtual uint8 GetAttackingTeam(const AFortPlayerControllerAthena* PlayerController = nullptr) const;

	UFUNCTION(BlueprintPure, Category="Teams")
	virtual uint8 GetDefendingTeam(const AFortPlayerControllerAthena* PlayerController = nullptr) const;

protected:
	UFUNCTION()
	void FinishRoundIntro(AFortAthenaMutator_ShowPlacard* ShowPlacardMutator);

	UFUNCTION()
	void OnRep_ModeState(FInfiltrationModeState OldState);

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnCaptured();

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnDownloaded();

	UPROPERTY(EditDefaultsOnly, Category="Classes")
	FScalableFloat GroundTimer;

	UPROPERTY(Replicated, meta=(ArraySizeEnum="/Script/FortniteGame.EInfiltrationTeam"))
	FInfiltrationTeamInfo InfiltrationTeamInfos[2];

	UPROPERTY(EditDefaultsOnly, Category="Win Condition")
	FScalableFloat CaptureTimeRequired;

	UPROPERTY(EditDefaultsOnly, Category="Win Condition")
	FScalableFloat CaptureRange;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FIconDisplayData IntelIconData;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FIconDisplayData IntelCapturePointIconData;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FSlateBrush Brush_UpArrow;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FSlateBrush Brush_DownArrow;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	float VerticalBuffer;

	UPROPERTY(EditAnywhere, Category="Rounds")
	FScalableFloat TimeToBlockRespawnBetweenRounds;

	UPROPERTY(EditAnywhere, Category="Rounds")
	FScalableFloat NumOfActiveCapturePoints;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	TSubclassOf<UGameplayEffect> PerkUnlockedGameplayEffectClass;

	UPROPERTY(ReplicatedUsing=OnRep_ModeState)
	FInfiltrationModeState ModeState;

	UPROPERTY(Replicated)
	TObjectPtr<AInfiltrationCarryObjectSpawnPoint> CurrentSpawnPoint;

	UPROPERTY(Replicated)
	TObjectPtr<AInfiltrationCarryObjectCapturePoint> CurrentCapturePoint;

	UPROPERTY(Replicated)
	TArray<FInfiltrationPOIInfo> POIInfo;

	UPROPERTY(EditAnywhere, Category="Accolade Tags")
	FGameplayTag RoundAccoladeTag;

	UPROPERTY(EditAnywhere, Category="Accolade Tags")
	FGameplayTag RoundWinAccoladeTag;

	UPROPERTY(EditAnywhere, Category="Accolade Tags")
	FGameplayTag MostRoundsAccoladeTag;

	UPROPERTY(EditAnywhere, Category="Accolade Tags")
	FGameplayTag PlayedInfAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Attacker_Win;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Attacker_Lose;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Defender_Win;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Defender_Lose;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TArray<FRoundCosmeticInfo> RoundCosmeticInfo;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FScalableFloat bRoundIntroEnabled;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_Infiltration")
	TObjectPtr<UCurveFloat> DilationCurve;

	UPROPERTY(Replicated)
	TWeakObjectPtr<AFortAthenaMutator_RoundHelper> CachedRoundHelper;

	UPROPERTY(Replicated)
	FVector IntelLocation;

};

UCLASS()
class UFortCheatManager_Infiltration : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

protected:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceCaptureIntel();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceDefendIntel();

};

