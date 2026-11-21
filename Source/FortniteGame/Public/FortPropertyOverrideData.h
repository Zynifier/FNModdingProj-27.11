// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPropertyOverrideReplication.h"
#include "FortPropertyOverrideData.generated.h"

class UObject;

UENUM()
enum class EPropertyOverrideTargetType : uint8
{
	None = 0,
	// No target object will be tracked

	Default = 1,
	// Property overrides will be applied against the target object directly

	ImmutableTarget = 2,
};

USTRUCT()
struct FPropertyOverrideMk2
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, SaveGame, Category="PropertyOverrideMk2")
	FString PropertyScope;

	UPROPERTY(EditAnywhere, SaveGame, Category="PropertyOverrideMk2")
	FString PropertyName;

	UPROPERTY(EditAnywhere, SaveGame, Category="PropertyOverrideMk2")
	FString PropertyData;

	UPROPERTY(Transient)
	FString DefaultPropertyData;

};

USTRUCT()
struct FPropertyOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, SaveGame, NotReplicated, Category="PropertyOverrideData")
	TArray<FPropertyOverrideMk2> PropertyOverrides;

	UPROPERTY(Transient)
	TArray<FPropertyOverrideId> SharedPropertyIds;

	UPROPERTY(Transient, NotReplicated)
	TArray<FPropertyOverrideId> PendingPropertyIds;

private:
	UPROPERTY(Transient)
	EPropertyOverrideTargetType OverrideMode;

	UPROPERTY(Transient)
	TObjectPtr<UObject> BaseObject;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UObject> MutableObject;

};

USTRUCT()
struct FPropertyOverridePropertyDataRedirect
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PropertyKnobName;

	UPROPERTY()
	FString ClassName;

	UPROPERTY()
	FString PropertyName;

	UPROPERTY()
	FString OptionClassName;

	UPROPERTY()
	FString OldPropertyData;

	UPROPERTY()
	FString NewPropertyData;

};

USTRUCT()
struct FPropertyOverrideRedirect
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ClassName;

	UPROPERTY()
	FString OldPropertyScope;

	UPROPERTY()
	FString OldPropertyName;

	UPROPERTY()
	FString NewPropertyScope;

	UPROPERTY()
	FString NewPropertyName;

};

UINTERFACE(MinimalAPI)
class UFortPropertyOverrideDataAccessor : public UInterface
{
	GENERATED_BODY()
};

class IFortPropertyOverrideDataAccessor
{
	GENERATED_BODY()

};

UCLASS(Abstract, Config=Redirect, DefaultConfig)
class UFortPropertyOverrideRedirects : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FPropertyOverrideRedirect> PropertyOverrideRedirects;

};

UCLASS()
class UFortPropertyOverrideInheritors : public UFortPropertyOverrideRedirects
{
	GENERATED_BODY()

};

UCLASS(Config=Redirect, DefaultConfig)
class UFortPropertyOverridePropertyDataRedirects : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FPropertyOverridePropertyDataRedirect> PropertyOverridePropertyDataRedirects;

};

UINTERFACE()
class UFortPropertyOverrideProvider : public UInterface
{
	GENERATED_BODY()
};

class IFortPropertyOverrideProvider
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortPropertyOverrideReplacements : public UFortPropertyOverrideRedirects
{
	GENERATED_BODY()

};

