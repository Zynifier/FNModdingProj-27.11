// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ActorComponent_ReplicatedParamHelper.generated.h"

class UActorComponent_ReplicatedParamHelper;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReplicatedParamChanged, const FGameplayTag&, ParamTag);

USTRUCT()
struct FRepParamBase : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGameplayTag Tag;

};

USTRUCT()
struct FRepParamBaseArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UActorComponent_ReplicatedParamHelper> CachedRepParamHelperComponent;

};

USTRUCT()
struct FRepParamBool : public FRepParamBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	uint8 Value : 1;

};

USTRUCT()
struct FRepParamBoolArray : public FRepParamBaseArray
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FRepParamBool> RepParamArray;

};

USTRUCT()
struct FRepParamFloat : public FRepParamBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	float Value;

};

USTRUCT()
struct FRepParamFloatArray : public FRepParamBaseArray
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FRepParamFloat> RepParamArray;

};

USTRUCT()
struct FRepParamInteger : public FRepParamBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 Value;

};

USTRUCT()
struct FRepParamIntegerArray : public FRepParamBaseArray
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FRepParamInteger> RepParamArray;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UActorComponent_ReplicatedParamHelper : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual void GetParamAsBool(const FGameplayTag ParamTag, bool& Value, bool& bValidParam);

	UFUNCTION(BlueprintPure)
	virtual void GetParamAsFloat(const FGameplayTag ParamTag, float& Value, bool& bValidParam);

	UFUNCTION(BlueprintPure)
	virtual void GetParamAsInt(const FGameplayTag ParamTag, int32& Value, bool& bValidParam);

	UFUNCTION(BlueprintCallable)
	void ResendAllParamChangedEvents();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual bool SendParamAsBool(const FGameplayTag& ParamTag, bool Value, bool bForceParamDirty = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual bool SendParamAsFloat(const FGameplayTag& ParamTag, float Value, bool bForceParamDirty = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual bool SendParamAsInt(const FGameplayTag& ParamTag, int32 Value, bool bForceParamDirty = false);

	UPROPERTY(BlueprintAssignable)
	FOnReplicatedParamChanged OnReplicatedParamChanged;

private:
	UPROPERTY(Transient, Replicated)
	FRepParamFloatArray ParamFloatsArray;

	UPROPERTY(Transient, Replicated)
	FRepParamIntegerArray ParamIntegersArray;

	UPROPERTY(Transient, Replicated)
	FRepParamBoolArray ParamBoolsArray;

};

