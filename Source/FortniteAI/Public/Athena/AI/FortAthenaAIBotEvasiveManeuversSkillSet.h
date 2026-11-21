// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotEvasiveManeuversSkillSet.generated.h"

USTRUCT()
struct FDigestedEvasiveManeuverSkillSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float JumpDelay;

	UPROPERTY(Transient)
	float JumpRandomDeviationDelay;

	UPROPERTY(Transient)
	float CrouchDelay;

	UPROPERTY(Transient)
	float CrouchRandomDeviationDelay;

	UPROPERTY(Transient)
	float DodgeDelay;

	UPROPERTY(Transient)
	float DodgeRandomDeviationDelay;

	UPROPERTY(Transient)
	float CrouchOverlayWeight;

	UPROPERTY(Transient)
	float JumpOverlayWeight;

	UPROPERTY(Transient)
	float NoOverlayWeight;

	UPROPERTY(Transient)
	float DodgeWeight;

	UPROPERTY(Transient)
	float DodgeJumpWeight;

	UPROPERTY(Transient)
	float DodgeDistanceMax;

	UPROPERTY(Transient)
	float DodgeDistanceMin;

	UPROPERTY(Transient)
	float CrouchTimeMax;

	UPROPERTY(Transient)
	float CrouchTimeMin;

	UPROPERTY(Transient)
	FString DebugName;

};

USTRUCT()
struct FDigestedEvasiveManeuverSkillSettingsSpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float OddsToBeUsed;

	UPROPERTY(Transient)
	float MaxDuration;

	UPROPERTY(Transient)
	float MaxDurationRandomDeviation;

	UPROPERTY(Transient)
	float Cooldown;

	UPROPERTY(Transient)
	float CooldownRandomDeviation;

	UPROPERTY(Transient)
	float DistanceMinSquared;

	UPROPERTY(Transient)
	float DistanceMaxSquared;

	UPROPERTY(Transient)
	FGameplayTagQuery WeaponTagQuery;

	UPROPERTY(Transient)
	FDigestedEvasiveManeuverSkillSettings EvasiveManeuverSkillSettings;

};

USTRUCT()
struct FEvasiveManeuverSkillSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CrouchOverlayWeight;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat JumpOverlayWeight;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat NoOverlayWeight;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DodgeWeight;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DodgeJumpWeight;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat JumpDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat JumpRandomDeviationDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CrouchDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CrouchRandomDeviationDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DodgeDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DodgeRandomDeviationDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DodgeDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DodgeDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CrouchTimeMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CrouchTimeMin;

};

USTRUCT()
struct FEvasiveManeuverSkillSettingsSpecialization
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat OddsToBeUsed;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDuration;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDurationRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat Cooldown;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat CooldownRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Debug", meta=(AllowPrivateAccess="true"))
	FString DebugName;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers")
	FGameplayTagQuery WeaponTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkillSettingsSpecialization", meta=(AllowPrivateAccess="true"))
	FEvasiveManeuverSkillSettings EvasiveManeuverSkillSettings;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotEvasiveManeuversDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FDigestedEvasiveManeuverSkillSettings DefaultEvasiveManeuverSkillSettings;

	UPROPERTY(Transient)
	TArray<FDigestedEvasiveManeuverSkillSettingsSpecialization> EvasiveManeuverSkillSettingsSpecializations;

	UPROPERTY(Transient)
	float JetpackStrafeDelay;

	UPROPERTY(Transient)
	float JetpackStrafeRandomDeviationDelay;

	UPROPERTY(Transient)
	float JetpackStrafeOverlayWeight;

	UPROPERTY(Transient)
	float JetpackStrafeDistanceMax;

	UPROPERTY(Transient)
	float JetpackStrafeDistanceMin;

	UPROPERTY(Transient)
	float JetpackStrafeActivationTime;

	UPROPERTY(Transient)
	float JetpackStrafeActivationTimeRandomDeviation;

	UPROPERTY(Transient)
	float JetpackStrafeTime;

	UPROPERTY(Transient)
	float JetpackStrafeTimeRandomDeviation;

	UPROPERTY(Transient)
	float DodgeMaxDistanceSquared;

	UPROPERTY(Transient)
	float CrouchMaxDistanceSquared;

	UPROPERTY(Transient)
	float JumpMaxDistanceSquared;

	UPROPERTY(Transient)
	float JetpackStrafeMaxDistanceSquared;

	UPROPERTY(Transient)
	float AvoidProjectilesReactionDistanceSqr;

	UPROPERTY(Transient)
	float AvoidProjectilesReactionTimeMin;

	UPROPERTY(Transient)
	float AvoidProjectilesReactionTimeMax;

	UPROPERTY(Transient)
	float AvoidProjectilesEvasiveDistanceMin;

	UPROPERTY(Transient)
	float AvoidProjectilesEvasiveDistanceMax;

	UPROPERTY(Transient)
	float AvoidPhysicsObjectsReactionDistanceMin;

	UPROPERTY(Transient)
	float AvoidPhysicsObjectsReactionDistanceMax;

	UPROPERTY(Transient)
	float AvoidPhysicsObjectsSpeedMin;

	UPROPERTY(Transient)
	float AvoidPhysicsObjectsSpeedMax;

	UPROPERTY(Transient)
	FGameplayTagQuery CanUseEvasiveManeuversTagQuery;

	UPROPERTY(Transient)
	bool bCanCrouchInUrgentMovement;

	UPROPERTY(Transient)
	bool bCanDodgeInUrgentMovement;

	UPROPERTY(Transient)
	bool bCanJumpInUrgentMovement;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotEvasiveManeuversSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkills", meta=(AllowPrivateAccess="true", DisplayName="Default Settings"))
	FEvasiveManeuverSkillSettings DefaultEvasiveManeuverSkillSettings;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuverSkills", meta=(AllowPrivateAccess="true", DisplayName="Settings Specializations"))
	TArray<FEvasiveManeuverSkillSettingsSpecialization> EvasiveManeuverSkillSettingsSpecializations;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat JetpackStrafeOverlayWeight;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat JetpackStrafeDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat JetpackStrafeRandomDeviationDelay;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="50.000000", UIMin="50.000000"))
	FScalableFloat JetpackStrafeDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="50.000000", UIMin="50.000000"))
	FScalableFloat JetpackStrafeDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="50.000000", UIMin="50.000000"))
	FScalableFloat JetpackStrafeActivationTime;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="50.000000", UIMin="50.000000"))
	FScalableFloat JetpackStrafeActivationTimeRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="50.000000", UIMin="50.000000"))
	FScalableFloat JetpackStrafeTime;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="50.000000", UIMin="50.000000"))
	FScalableFloat JetpackStrafeTimeRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat DodgeMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanDodgeInUrgentMovement;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat CrouchMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanCrouchInUrgentMovement;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat JumpMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanJumpInUrgentMovement;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat JetpackStrafeMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidProjectilesReactionDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidProjectilesReactionTimeMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidProjectilesReactionTimeMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidProjectilesEvasiveDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidProjectilesEvasiveDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidPhysicsObjectsReactionDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidPhysicsObjectsReactionDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidPhysicsObjectsSpeedMin;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat AvoidPhysicsObjectsSpeedMax;

	UPROPERTY(EditDefaultsOnly, Category="EvasiveManeuvers")
	FGameplayTagQuery CanUseEvasiveManeuversTagQuery;

};

