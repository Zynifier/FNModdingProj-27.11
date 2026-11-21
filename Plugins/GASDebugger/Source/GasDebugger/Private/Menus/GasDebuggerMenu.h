// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "GasEventHistory.h"
#include "ImGuiDebugMenuBase.h"
#include "GasDebuggerMenu.generated.h"

class AActor;
class UGameplayAbility;
class UGameplayEffect;

UENUM()
enum class EGasDebuggerFilterMode : uint8
{
	Show = 0,
	Highlight = 1,
};

UENUM()
enum class EGasDebuggerSection : uint8
{
	Tags = 0,
	Abilities = 1,
	Effects = 2,
	EventHistory = 3,
	Attributes = 4,
	NumSections = 5,
};

USTRUCT()
struct GASDEBUGGER_API FGasDebugAbilitySnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSubclassOf<UGameplayAbility> Ability;

	UPROPERTY(Transient)
	int32 Level;

	UPROPERTY(Transient)
	bool bIsActive;

	UPROPERTY(Transient)
	bool bIsReplicated;

};

USTRUCT()
struct GASDEBUGGER_API FGasDebugEffectSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayEffectContext Context;

	UPROPERTY(Transient)
	TSubclassOf<UGameplayEffect> Effect;

};

USTRUCT()
struct GASDEBUGGER_API FGasDebugReplicatableCallStack
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint16 EventId;

	UPROPERTY()
	FString BlueprintCallStack;

	UPROPERTY()
	TArray<uint64> NativeCallStack;

};

USTRUCT()
struct GASDEBUGGER_API FGasDebugSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FGameplayTag> ActiveTags;

	UPROPERTY(Transient)
	TArray<int8> ActiveTagCounts;

	UPROPERTY(Transient)
	TArray<FString> AttributeNames;

	UPROPERTY(Transient)
	TArray<float> AttributeBaseValues;

	UPROPERTY(Transient)
	TArray<float> AttributeFinalValues;

	UPROPERTY(Transient)
	TArray<FGasDebugEffectSnapshot> ActiveEffectSnapshots;

	UPROPERTY(Transient)
	TArray<FGasDebugAbilitySnapshot> AbilitySnapshots;

	UPROPERTY(Transient)
	TArray<FGasEventHistoryItem> EventHistory;

};

UCLASS()
class GASDEBUGGER_API AGasDebuggerMenu : public AImGuiDebugMenuBase
{
	GENERATED_BODY()

private:
	UFUNCTION(Client, Reliable)
	void ClientReceiveCallStack(FGasDebugReplicatableCallStack CallStack);

	UFUNCTION(Server, Reliable)
	void ServerClose();

	UFUNCTION(Server, Reliable)
	void ServerRemoveEffect(const FString& EffectUsefulName);

	UFUNCTION(Server, Reliable)
	void ServerRemoveTag(const FGameplayTag& Tag);

	UFUNCTION(Server, Reliable)
	void ServerRequestCallStack(uint16 Id);

	UFUNCTION(Server, Reliable)
	void ServerSetAttribute(const FString& AttributeName, float NewValue);

	UFUNCTION(Server, Reliable)
	void ServerSetMonitoredActor(AActor* ActorToMonitor);

	UFUNCTION(Server, Reliable)
	void ServerTogglePause();

	UPROPERTY(Transient, Replicated)
	AActor* MonitoredActor;

	UPROPERTY(Transient)
	TArray<AActor*> NearbyActorsWithASC;

	UPROPERTY(Transient)
	int32 EditedAttributeIndex;

	UPROPERTY(Transient)
	float EditedAttributeValue;

	UPROPERTY(Transient)
	int32 EventHistoryClassFilterFlags;

	UPROPERTY(Transient)
	EGasDebuggerSection Section;

	UPROPERTY(Transient)
	EGasDebuggerSection NextSection;

	UPROPERTY(Transient)
	bool bIsDataPaused;

	UPROPERTY(Transient)
	bool bIsInputEnabled;

	UPROPERTY(Transient)
	bool bWasActorSelectionOpenLastFrame;

	UPROPERTY(Transient)
	bool bDisplayClient;

	UPROPERTY(Transient)
	bool bDisplayServer;

	UPROPERTY(Transient)
	EGasDebuggerFilterMode FilterMode;

	UPROPERTY(Transient, Replicated)
	FGasDebugSnapshot ServerGasDebugSnapshot;

	UPROPERTY(Transient)
	FGasDebugSnapshot PausedServerGasDebugSnapshot;

	UPROPERTY(Transient)
	FGasDebugSnapshot PausedClientGasDebugSnapshot;

	UPROPERTY(Transient)
	TArray<FGasDebugReplicatableCallStack> ReceivedCallStacks;

	UPROPERTY(Transient)
	TArray<uint16> CurrentlyRequestingCallStacks;

};

