// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Online/FortKickReasons.h"
#include "Player/FortPlayerState.h"
#include "FortPlayerStateZone.generated.h"

class AFortCarriedObject;
class AFortPlayerStateZone;
class UFortGadgetItemDefinition;
class UFortItemDefinition;
class UFortWorldItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAccumulatedItemsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeginSpectating, AFortPlayerStateZone*, Spectator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCurrentPawnChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndSpectating, AFortPlayerStateZone*, Spectator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOvershieldVisibilityChanged, bool, bNewVisible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpectatingTargetChanged, AFortPlayerStateZone*, SpectatingTarget);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpectatorCountChanged, int32, SpectatorCount);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpectatorsChanged, int32, Num);

USTRUCT()
struct FAccumulatedItemEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> ItemDefinition;

	UPROPERTY()
	int32 Quantity;

};

USTRUCT()
struct FFortSpectatorZoneItem : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateZone> PlayerState;

};

USTRUCT()
struct FFortSpectatorZoneArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortSpectatorZoneItem> SpectatorArray;

	UPROPERTY(NotReplicated)
	TObjectPtr<AFortPlayerStateZone> OwningState;

};

USTRUCT()
struct FSimulatedAttributeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayAttribute Attribute;

	UPROPERTY()
	float CurrentValue;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayerStateZone : public AFortPlayerState
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSkydivedFromBusAndLanded, bool, bSkydivedFromBusAndLanded);

public:
	UFUNCTION(BlueprintCallable, Category="HealthSet")
	void GetHealthAndShields(float& Health, float& HealthMax, float& Shield, float& ShieldMax);

	UFUNCTION(BlueprintPure, Category="AccumulatedItems")
	int32 GetNumOfAccumulatedBluGlo() const;

	UFUNCTION(BlueprintPure, Category="AccumulatedItems")
	int32 GetNumOfAccumulatedItem(const UFortWorldItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintCallable, Category="HealthSet")
	void GetOvershields(float& Overshield, float& OvershieldMax);

	UFUNCTION(BlueprintPure, Category="PlayerState")
	virtual FString GetPlayerNameForStreaming() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="GadgetAttributeSets")
	float GetSimulatedAttributeValue(const FGameplayAttribute& Attribute, const float DefaultValue) const;

	UFUNCTION(BlueprintCallable)
	int32 GetSpectatorCount();

	UFUNCTION(BlueprintPure)
	bool HasEverSkydivedFromBus() const;

	UFUNCTION(BlueprintPure)
	bool HasEverSkydivedFromBusAndLanded() const;

	UFUNCTION(BlueprintPure)
	virtual bool IsPlayerDead() const;

	UFUNCTION(NetMulticast, Reliable)
	void MulticastTriggerOnGadgetTrackedAttributeDestroyedFX(const UFortGadgetItemDefinition* GadgetItemDefinition);

	UFUNCTION()
	void OnRep_AccumulatedItems();

	UFUNCTION()
	void OnRep_OvershieldBarVisisble();

	UFUNCTION()
	virtual void OnRep_SpectatingTarget();

	UFUNCTION(Server, Reliable)
	void ServerSetInAircraft(bool bNewInAircraft);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SetOvershieldBarVisible(bool NewVisible);

	UFUNCTION(BlueprintPure)
	bool ShouldOvershieldBarBeVisible() const;

	UPROPERTY(BlueprintAssignable, Category="Pawn")
	FOnCurrentPawnChanged OnCurrentPawnChanged;

	UPROPERTY(Replicated)
	FFortSpectatorZoneArray Spectators;

	UPROPERTY(BlueprintAssignable)
	FOnSpectatorsChanged OnSpectatorsRemovedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnSpectatorCountChanged OnSpectatorCountChangedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnSpectatingTargetChanged OnSpectatingTargetChangedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnBeginSpectating OnBeginSpectatingEvent;

	UPROPERTY(BlueprintAssignable)
	FOnOvershieldVisibilityChanged OnOvershieldVisibilityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnSkydivedFromBusAndLanded OnSkydivedFromBusAndLanded;

	UPROPERTY(BlueprintAssignable, Category="AccumulatedItems")
	FOnAccumulatedItemsChanged OnAccumulatedItemsChanged;

protected:
	UFUNCTION()
	void OnRep_HasEverSkydivedFromBusAndLanded();

	UFUNCTION()
	void OnRep_NumRejoins();

	UFUNCTION()
	virtual void OnRep_QuickbarEquippedItems();

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortReplicatedStat"))
	FReplicatedStatValues RS_Zone_Old[35];

	UPROPERTY(Transient)
	TObjectPtr<UFortGadgetItemDefinition> PendingDestroyedGadgetItemDefinition;

private:
	UPROPERTY(ReplicatedUsing=OnRep_SpectatingTarget)
	TWeakObjectPtr<AFortPlayerStateZone> SpectatingTarget;

	UPROPERTY(Replicated)
	EFortKickReason KickedFromSessionReason;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category="FortPlayerStateZone", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortCarriedObject> CarriedObject;

	UPROPERTY(ReplicatedUsing=OnRep_NumRejoins)
	int32 NumRejoins;

	UPROPERTY(Transient)
	int32 OldTotalScoreStat;

	UPROPERTY(Replicated)
	bool bInvincibleDueToUI;

	UPROPERTY(Replicated)
	float CurrentHealth;

	UPROPERTY(Replicated)
	float MaxHealth;

	UPROPERTY(Replicated)
	float CurrentShield;

	UPROPERTY(Replicated)
	float MaxShield;

	UPROPERTY(Replicated)
	float CurrentOvershield;

	UPROPERTY(Replicated)
	float MaxOvershield;

	UPROPERTY(Replicated)
	float CurrentSignalInStorm;

	UPROPERTY(Replicated)
	float MaxSignalInStorm;

	UPROPERTY(ReplicatedUsing=OnRep_OvershieldBarVisisble)
	bool bOvershieldBarVisible;

	UPROPERTY(ReplicatedUsing=OnRep_AccumulatedItems)
	TArray<FAccumulatedItemEntry> AccumulatedItems;

	UPROPERTY(Replicated)
	TArray<FSimulatedAttributeEntry> SimulatedAttributes;

	UPROPERTY(Transient, Replicated)
	uint8 bInAircraft : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bHasEverSkydivedFromBus : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HasEverSkydivedFromBusAndLanded)
	uint8 bHasEverSkydivedFromBusAndLanded : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_QuickbarEquippedItems)
	TArray<TObjectPtr<UFortItemDefinition>> QuickbarEquippedItems;

};

