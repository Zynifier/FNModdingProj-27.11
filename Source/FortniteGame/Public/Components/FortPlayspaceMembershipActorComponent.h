// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "FortPlayspaceMembershipActorComponent.generated.h"

class AActor;
class APlayspace;
class UFortPlayspaceMembershipActorComponent;
class UPlayspaceComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFortPlayspaceMembershipChanged, APlayspace*, NewBoundPlayspace);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPlayspaceMembershipActorComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortPlayspaceMembershipActorComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Playspace", meta=(DefaultToSelf="Owner"))
	static UFortPlayspaceMembershipActorComponent* FindOrCreatePlayspaceMembershipActorComponentOnActor(const AActor* Owner);

	UFUNCTION(BlueprintCallable, Category="Playspace", meta=(ComponentClass="/Script/PlayspaceSystem.PlayspaceComponent", DefaultToSelf="Owner", DeterminesOutputType="ComponentClass"))
	static UPlayspaceComponent* FindOrCreatePlayspaceMembershipComponentAndReturnComponent(TSubclassOf<UPlayspaceComponent> ComponentClass, const AActor* Owner);

	UFUNCTION(BlueprintPure, Category="Playspace")
	APlayspace* GetBoundPlayspace() const;

	UFUNCTION(BlueprintPure, Category="Playspace", meta=(ComponentClass="/Script/PlayspaceSystem.Playspace", DeterminesOutputType="PlayspaceClass"))
	APlayspace* GetBoundPlayspaceByClass(TSubclassOf<APlayspace> PlayspaceClass) const;

	UFUNCTION(BlueprintPure, Category="Playspace", meta=(ComponentClass="/Script/PlayspaceSystem.PlayspaceComponent", DeterminesOutputType="ComponentClass"))
	UPlayspaceComponent* GetBoundPlayspaceComponent(TSubclassOf<UPlayspaceComponent> ComponentClass) const;

	UPROPERTY(BlueprintAssignable)
	FOnFortPlayspaceMembershipChanged OnFortPlayspaceMembershipChanged;

private:
	UFUNCTION()
	void AttemptToBindToPlayspace();

	UFUNCTION()
	void HandleBoundPlayspaceEndplayEvent(AActor* InOwner, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void OnRep_BoundPlayspace();

	UPROPERTY(EditAnywhere, Category="FortPlayspaceMembershipActorComponent")
	FGameplayTag CustomRequiredTagForPlayspace;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BoundPlayspace)
	TWeakObjectPtr<APlayspace> BoundPlayspace;

};

