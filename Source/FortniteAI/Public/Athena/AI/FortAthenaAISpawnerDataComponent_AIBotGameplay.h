// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "AI/FortAthenaAIBotController.h"
#include "AI/FortBotNameSettings.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_GameplayBase.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "FortAthenaAISpawnerDataComponent_AIBotGameplay.generated.h"

class AFortAthenaPatrolPath;
class UFortAthenaAIBotSkillSet;
class UFortAthenaAIRuntimeParameters_Leash;
class UFortAthenaAISpawnerDataComponentList;
class UFortBotNameSettings;
class UFortPawnComponent_AIBotPingCommand;

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_AIBotConvert : public UFortAthenaAIRuntimeParameters_AIConvert
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bShouldLeashFollowConverter : 1;

	UPROPERTY(Transient)
	uint8 bShouldScanAroundWhenWaiting : 1;

	UPROPERTY(Transient)
	uint8 bFollowingBehaviorEnabled : 1;

	UPROPERTY(Transient)
	uint8 bFollowerCanUseDBNO : 1;

	UPROPERTY(Transient)
	uint8 bMimicBehaviorEnabled : 1;

	UPROPERTY(Transient)
	uint8 bShouldTeleportTowardsConverter : 1;

	UPROPERTY(Transient)
	uint8 bCanDanceWithConverter : 1;

	UPROPERTY(Transient)
	uint8 bTargetPawnConverterDamaged : 1;

	UPROPERTY(Transient)
	uint8 bCanHolsterWeaponWhileConverted : 1;

	UPROPERTY(Transient)
	float SkillLevelOverride;

	UPROPERTY(Transient)
	float PreConversionSkillLevel;

	UPROPERTY(Transient)
	float InnerLeashRadius;

	UPROPERTY(Transient)
	float OuterLeashRadius;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_Leash> PreConversionLeashParams;

	UPROPERTY(Transient)
	float LeashFollowActorUpdateRate;

	UPROPERTY(Transient)
	FVector LeashFollowActorLocalOffset;

	UPROPERTY(Transient)
	float FollowingBehaviorRadiusSqr;

	UPROPERTY(Transient)
	float FollowingBehaviorRadius;

	UPROPERTY(Transient)
	float FollowingBehaviorUrgenceRadiusSqr;

	UPROPERTY(Transient)
	float FollowingBehaviorUrgenceRadius;

	UPROPERTY(Transient)
	float FollowingBehaviorBlockedSightAngleRad;

	UPROPERTY(Transient)
	float FollowingBehaviorBlockedSightExitAngleRad;

	UPROPERTY(Transient)
	float FollowingBehaviorBlockedSightExitDistMin;

	UPROPERTY(Transient)
	float MimicBehaviorRadiusSqr;

	UPROPERTY(Transient)
	float MimicBehaviorRadius;

	UPROPERTY(Transient)
	float TeleportTowardsConverterDistanceSq;

	UPROPERTY(Transient)
	float TeleportTowardsConverterInCombatDistanceSq;

	UPROPERTY(Transient)
	float TeleportTowardsConverterWhenNotVisibleDistanceSq;

	UPROPERTY(Transient)
	float TeleportTowardsConverterInCombatWhenNotVisibleDistanceSq;

	UPROPERTY(Transient)
	float MinDistanceFromConverterWhenTeleported;

	UPROPERTY(Transient)
	float MaxDistanceFromConverterWhenTeleported;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> ConvertedSkillSetClasses;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> PreConversionSkillSetClasses;

};

UCLASS(BlueprintType)
class UFortAthenaAIRuntimeParameters_AIBotRespawn : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAIRuntimeParameters_AIBotRespawn", meta=(AllowPrivateAccess="true"))
	uint8 bCanRespawnOnDeath : 1;

	UPROPERTY(Transient)
	uint8 bRespawnOnDeathLocation : 1;

	UPROPERTY(Transient)
	float RespawnTime;

	UPROPERTY(Transient)
	FVector RespawnLocationOverride;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAISpawnerDataComponentList> AISpawnerDataComponentList;

};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_Leash : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FVector LeashLocation;

	UPROPERTY(Transient)
	float LeashInnerRadius;

	UPROPERTY(Transient)
	float LeashOuterRadius;

	UPROPERTY(Transient)
	float LeashTeleportRadius;

	UPROPERTY(Transient)
	bool bCheckForReachabilityOnRandomLocationGeneration;

	UPROPERTY(Transient)
	ELeashReturnLocationMode LeashReturnLocationMode;

	UPROPERTY(Transient)
	FLeashInfoOverride DefaultLeashInfo;

	UPROPERTY(Transient)
	TMap<EAlertLevel, FLeashInfoOverride> AlertLevelLeashOverride;

};

UCLASS(MinimalAPI)
class UFortAthenaAISpawnerDataComponent_AIBotGameplay : public UFortAthenaAISpawnerDataComponent_GameplayBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetAssociatedPatrolPath(AFortAthenaPatrolPath* InAssociatedPatrolPath);

	UFUNCTION(BlueprintCallable)
	void SetLeashInnerRadius(const float InLeashInnerRadius);

	UFUNCTION(BlueprintCallable)
	void SetLeashLocation(const FVector InLeashLocation);

	UFUNCTION(BlueprintCallable)
	void SetLeashOuterRadius(const float InLeashOuterRadius);

	UFUNCTION(BlueprintCallable)
	void SetNameSettings(const EBotNamingMode::Type InNamingMode, const FString InName, const bool bInAddPlayerIDSuffix);

private:
	UPROPERTY(EditAnywhere, Instanced, Category="Name", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortBotNameSettings> NameSettings;

	UPROPERTY(EditAnywhere, Category="Name", meta=(AllowPrivateAccess="true"))
	uint8 bRequiresUniqueNetId : 1;

	UPROPERTY(EditAnywhere, Category="Respawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanRespawnOnDeath;

	UPROPERTY(EditAnywhere, Category="Respawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat RespawnOnDeathLocation;

	UPROPERTY(EditAnywhere, Category="Respawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat RespawnTime;

	UPROPERTY(EditAnywhere, Category="Relevancy", meta=(AllowPrivateAccess="true"))
	float PawnCullDistanceAfterPlayerAggroMode;

	UPROPERTY(EditAnywhere, Category="SafeLocation", meta=(AllowPrivateAccess="true"))
	EReachLocationValidationMode ReachLocationValidationMode;

	UPROPERTY(BlueprintReadOnly, Category="Leash", meta=(AllowPrivateAccess="true"))
	FVector LeashLocation;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	float LeashInnerRadius;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	float LeashOuterRadius;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	FScalableFloat LeashTeleportRadius;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	bool bCheckForReachabilityOnRandomLocationGeneration;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	ELeashReturnLocationMode LeashReturnLocationMode;

	UPROPERTY(EditAnywhere, Category="Leash", meta=(AllowPrivateAccess="true"))
	TMap<EAlertLevel, FLeashInfoOverride> AlertLevelLeashOverride;

	UPROPERTY(EditAnywhere, Category="Patrol", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortAthenaPatrolPath> AssociatedPatrolPath;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bCanInvestigateWithMeleeWeapon;

	UPROPERTY(EditAnywhere, Category="Mutators", meta=(AllowPrivateAccess="true"))
	bool bApplyMutatorsHealthAndShieldModifiers;

	UPROPERTY(EditAnywhere, Category="PawnFeatures", meta=(AllowPrivateAccess="true"))
	bool bSupportsTethering;

	UPROPERTY(EditAnywhere, Category="PawnFeatures", meta=(AllowPrivateAccess="true"))
	bool bEnableRenderCustomDepth;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bDisableGiveWeaponCheat;

	UPROPERTY(EditAnywhere, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bDisableGiveMaterialsCheat;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat InnerLeashRadius;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat OuterLeashRadius;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldLeashFollowConverter;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat LeashFollowActorUpdateRate;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FVector LeashFollowActorLocalOffset;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat SkillLevelOverride;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldScanAroundWhenWaiting;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldTeleportTowardsConverter;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowingBehaviorEnabled;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowerCanUseDBNO;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowingBehaviorRadius;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowingBehaviorUrgenceRadius;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowingBehaviorBlockedSightAngle;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowingBehaviorBlockedSightExitAngle;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat FollowingBehaviorBlockedSightExitDistMin;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat MimicBehaviorEnabled;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat MimicBehaviorRadius;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanDanceWithConverter;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat TeleportTowardsConverterDistance;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat TeleportTowardsConverterInCombatDistance;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat TeleportTowardsConverterWhenNotVisibleDistance;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat TeleportTowardsConverterInCombatWhenNotVisibleDistance;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinDistanceFromConverterWhenTeleported;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceFromConverterWhenTeleported;

	UPROPERTY(EditDefaultsOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> ConvertedSkillSetClasses;

	UPROPERTY(EditDefaultsOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortPawnComponent_AIBotPingCommand> PingCommandComponentClass;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat TargetPawnConverterDamaged;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanHolsterWeaponWhileConverted;

};

