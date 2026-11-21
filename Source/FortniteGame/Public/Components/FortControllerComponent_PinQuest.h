// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortControllerComponent_PinQuest.generated.h"

class UFortControllerComponent_PinQuest;
class UFortQuestItemDefinition_Athena;
enum class EAthenaPinnedQuestType : uint8;

UENUM(BlueprintType)
enum class EAllowedPinnedQuestTypes : uint8
{
	AllAllowed = 0,
	OnlyUserSelected = 1,
	OnlyConciergeSuggested = 2,
};

UENUM(BlueprintType)
enum class EAthenaPinnedQuestType : uint8
{
	UserSelected = 0,
	ConciergeSuggested = 1,
	NoPinnedQuest = 2,
};

USTRUCT()
struct FAthenaPinnedQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	UFortControllerComponent_PinQuest* PinnedQuestComponent;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_PinQuest : public UControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortOnPinnedQuestChanged, const FAthenaPinnedQuestData&, PinnedQuestData);

public:
	UFortControllerComponent_PinQuest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	EAthenaPinnedQuestType GetPinnedQuestType() const;

private:
	UFUNCTION(Client, Reliable)
	void ClientPinQuest(const UFortQuestItemDefinition_Athena* QuestDefToPin);

	UFUNCTION(Server, Reliable)
	void ServerPinQuest(const UFortQuestItemDefinition_Athena* QuestDefToPin);

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItemDefinition_Athena> PinnedQuest;

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItemDefinition_Athena> PinnedConciergeQuest;

	UPROPERTY(Transient)
	int32 AttemptedPinQuestCount;

};

