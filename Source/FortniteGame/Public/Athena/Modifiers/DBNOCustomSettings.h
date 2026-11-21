// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBNOCustomSettings.generated.h"

class AActor;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDBNOMutatorType : uint8
{
	Default = 0,
	On = 1 UMETA(DisplayName="Classic"),
	// This will now be considered 'Classic'

	Off = 2,
	Improved = 3,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ETenacityType : uint8
{
	Default = 0,
	// Use Tenacity Amount from DataTable

	MaxHealth = 1,
	// Tenacity Amount is the player's max health

	Custom = 2,
};

USTRUCT(BlueprintType)
struct FDBNOCustomSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	EDBNOMutatorType Enabled;

	UPROPERTY(BlueprintReadWrite, Transient, NotReplicated, Category="DBNOCustomSettings")
	float TenacityDepletionRate;

	UPROPERTY(BlueprintReadWrite, Transient, NotReplicated, Category="DBNOCustomSettings")
	float ReviveHealthPercentage;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bAllowRevives;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bAllowCarry;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	float TimeToRevive;

	UPROPERTY(BlueprintReadWrite, Transient, NotReplicated, Category="DBNOCustomSettings")
	bool bAlertTeam;

	UPROPERTY(BlueprintReadWrite, Transient, NotReplicated, Category="DBNOCustomSettings")
	bool LastManStandingMode;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bAllowInterrogation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bAllowInterrogationReveal;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	int32 SelectedTeam;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bTeamAffectsAllButSelected;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	int32 SelectedClass;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bClassAffectsAllButSelected;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	ETenacityType TenacityType;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	float TenacityAmount;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	bool bOverrideInvincibilityTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCustomSettings")
	float DownedInvincibilityTime;

};

USTRUCT()
struct FDBNOSettingsByActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> Actor;

	UPROPERTY(Transient)
	FDBNOCustomSettings Settings;

};

