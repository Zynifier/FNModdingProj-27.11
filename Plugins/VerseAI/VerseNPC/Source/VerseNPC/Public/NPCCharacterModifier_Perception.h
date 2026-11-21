// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterModifier.h"
#include "NPCCharacterModifier_Perception.generated.h"

class UAISenseConfig_Damage;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;
class UAISenseConfig_Touch;

UCLASS(Abstract, BlueprintType, meta=(DisplayName="Character Modifier Guard Perception"))
class VERSENPC_API UCharacterModifier_GuardPerception : public UNPCCharacterModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Sight")
	uint8 bOverrideSightSettings : 1;

	UPROPERTY(EditAnywhere, Category="Sight", meta=(EditCondition="bOverrideSightSettings"))
	uint8 bEnableSightSettings : 1;

	UPROPERTY(EditAnywhere, Category="Hearing")
	uint8 bOverrideHearingSettings : 1;

	UPROPERTY(EditAnywhere, Category="Hearing", meta=(EditCondition="bOverrideHearingSettings"))
	uint8 bEnableHearingSettings : 1;

	UPROPERTY(EditAnywhere, Category="Touch")
	uint8 bOverrideTouchSettings : 1;

	UPROPERTY(EditAnywhere, Category="Touch", meta=(EditCondition="bOverrideTouchSettings"))
	uint8 bEnableTouchSettings : 1;

	UPROPERTY(EditAnywhere, Category="Damage")
	uint8 bOverrideDamageSettings : 1;

	UPROPERTY(EditAnywhere, Category="Damage", meta=(EditCondition="bOverrideDamageSettings"))
	uint8 bEnableDamageSettings : 1;

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Sight", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EAlertLevel", EditCondition="bOverrideSightSettings && bEnableSightSettings"))
	TObjectPtr<UAISenseConfig_Sight> SightPerceptionSettings[4];

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Hearing", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EAlertLevel", EditCondition="bOverrideHearingSettings && bEnableHearingSettings"))
	TObjectPtr<UAISenseConfig_Hearing> HearingPerceptionSettings[4];

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Touch", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EAlertLevel", EditCondition="bOverrideTouchSettings && bEnableTouchSettings"))
	TObjectPtr<UAISenseConfig_Touch> TouchPerceptionSettings[4];

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Damage", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EAlertLevel", EditCondition="bOverrideDamageSettings && bEnableDamageSettings"))
	TObjectPtr<UAISenseConfig_Damage> DamagePerceptionSettings[4];

};

UCLASS(Abstract, BlueprintType, meta=(DisplayName="NPC Character Modifier Perception"))
class VERSENPC_API UNPCCharacterModifier_Perception : public UNPCCharacterModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Sight")
	uint8 bOverrideSightSettings : 1;

	UPROPERTY(EditAnywhere, Category="Sight", meta=(EditCondition="bOverrideSightSettings"))
	uint8 bEnableSightSettings : 1;

	UPROPERTY(EditAnywhere, Category="Hearing")
	uint8 bOverrideHearingSettings : 1;

	UPROPERTY(EditAnywhere, Category="Hearing", meta=(EditCondition="bOverrideHearingSettings"))
	uint8 bEnableHearingSettings : 1;

	UPROPERTY(EditAnywhere, Category="Touch")
	uint8 bOverrideTouchSettings : 1;

	UPROPERTY(EditAnywhere, Category="Touch", meta=(EditCondition="bOverrideTouchSettings"))
	uint8 bEnableTouchSettings : 1;

	UPROPERTY(EditAnywhere, Category="Damage")
	uint8 bOverrideDamageSettings : 1;

	UPROPERTY(EditAnywhere, Category="Damage", meta=(EditCondition="bOverrideDamageSettings"))
	uint8 bEnableDamageSettings : 1;

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Sight", meta=(EditCondition="bOverrideSightSettings && bEnableSightSettings", ShowInnerProperties))
	TObjectPtr<UAISenseConfig_Sight> SightPerceptionSettings;

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Hearing", meta=(EditCondition="bOverrideHearingSettings && bEnableHearingSettings", ShowInnerProperties))
	TObjectPtr<UAISenseConfig_Hearing> HearingPerceptionSettings;

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Touch", meta=(EditCondition="bOverrideTouchSettings && bEnableTouchSettings", ShowInnerProperties))
	TObjectPtr<UAISenseConfig_Touch> TouchPerceptionSettings;

	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Damage", meta=(EditCondition="bOverrideDamageSettings && bEnableDamageSettings", ShowInnerProperties))
	TObjectPtr<UAISenseConfig_Damage> DamagePerceptionSettings;

};

