// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "SidewaysStateComponent.generated.h"

class ASidewaysPlayspace;
class USidewaysStateComponent;
enum class ESidewaysState : uint8;

UENUM(BlueprintType)
enum class ESidewaysState : uint8
{
	InNormalWorld = 0,
	InSidewaysWorld = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSidewaysStateChanged, USidewaysStateComponent*, SidewaysStateComponent, ASidewaysPlayspace*, SidewaysPlayspace, ESidewaysState, OldState, ESidewaysState, NewState);

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class USidewaysStateComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	USidewaysStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	ESidewaysState GetSidewaysState() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetSidewaysState(ESidewaysState NewState, ASidewaysPlayspace* NewSidewaysPlayspace = nullptr);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSidewaysStateChanged(ASidewaysPlayspace* NewSidewaysPlayspace, ESidewaysState OldState, ESidewaysState NewState);

	UFUNCTION()
	void OnRep_SidewaysPlayspace(ASidewaysPlayspace* NewSidewaysPlayspace);

	UFUNCTION()
	void OnRep_SidewaysState(ESidewaysState LastSidewaysState);

	UPROPERTY(ReplicatedUsing=OnRep_SidewaysState)
	ESidewaysState SidewaysState;

	UPROPERTY(ReplicatedUsing=OnRep_SidewaysPlayspace)
	TObjectPtr<ASidewaysPlayspace> SidewaysPlayspace;

	UPROPERTY(BlueprintAssignable)
	FSidewaysStateChanged OnSidewaysStateChangedDelegate;

};

