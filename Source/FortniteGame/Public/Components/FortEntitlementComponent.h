// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "FortEntitlementComponent.generated.h"

UENUM()
enum class EFortEntitlementState : uint8
{
	NotRequested = 0,
	Requesting = 1,
	RequestError = 2,
	NotGranted = 3,
	Granted = 4,
	DevGranted = 5,
};

USTRUCT()
struct FFortEntitlementNameAndTag
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FName ComponentTag;

};

USTRUCT()
struct FFortEntitlementConfig : public FFortEntitlementNameAndTag
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProdId;

	UPROPERTY()
	FString GameDevId;

	UPROPERTY()
	FString Namespace;

};

USTRUCT()
struct FFortEntitlementStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

};

USTRUCT()
struct FFortEntitlementState : public FFortEntitlementStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortEntitlementState State;

};

UCLASS()
class UFortEntitlementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_Entitlements();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Entitlements)
	TArray<FFortEntitlementState> Entitlements;

};

UCLASS(Config=Game)
class UFortEntitlementComponentConfig : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FFortEntitlementConfig> Entitlements;

	UPROPERTY(Config)
	TArray<FFortEntitlementNameAndTag> ForceOnInPIE;

};

