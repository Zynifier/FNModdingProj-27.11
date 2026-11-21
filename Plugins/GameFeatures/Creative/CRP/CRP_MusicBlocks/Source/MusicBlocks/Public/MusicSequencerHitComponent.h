// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/NetSerialization.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/Actor.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "PlayspaceComponent.h"
#include "MusicSequencerHitComponent.generated.h"

class AActor;
class AController;
class AMusicSequencerHitActor;
class APlayerState;
class IFortMusicSequencerInterface;
class UMusicSequencerHitComponent;
class UObject;
class USoundBase;

USTRUCT()
struct FMusicSequencerHitHandle
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	uint64 Handle;

};

USTRUCT()
struct FMusicSequencerHitEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FMusicSequencerHitHandle Handle;

	UPROPERTY()
	float ServerWorldTimeStart;

	UPROPERTY()
	TSubclassOf<AActor> ActorClass;

	UPROPERTY()
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY()
	TWeakObjectPtr<APlayerState> InstigatorPlayerState;

	UPROPERTY()
	FVector_NetQuantize SoundLocation;

	UPROPERTY()
	int32 SoundIndex;

	UPROPERTY(NotReplicated)
	FTimerHandle TimerHandle;

};

USTRUCT()
struct FMusicSequencerHitArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FMusicSequencerHitEntry> Items;

	UPROPERTY(Export)
	TWeakObjectPtr<UMusicSequencerHitComponent> OwningComponent;

};

UCLASS()
class MUSICBLOCKS_API AMusicSequencerHitActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UMusicSequencerHitComponent* GetMusicSequencerHitComponent() const;

protected:
	UPROPERTY(VisibleDefaultsOnly, Export, Category="MusicSequencerHitActor", meta=(EditInline="true"))
	UMusicSequencerHitComponent* MusicSequencerHitComponent;

};

UCLASS(HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD", "Trigger", "PhysicsVolume"))
class MUSICBLOCKS_API UMusicSequencerHitAdderComponent : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	AMusicSequencerHitActor* GetMusicSequencerHitActor() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="MusicSequencer")
	TSubclassOf<AMusicSequencerHitActor> MusicSequencerHitActorClass;

	UPROPERTY()
	TWeakObjectPtr<AMusicSequencerHitActor> MusicSequencerHitActor;

};

UCLASS(HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD"))
class MUSICBLOCKS_API UMusicSequencerHitComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static bool RegisterMusicSequencerActor(const UObject* WorldContextObject, TScriptInterface<IFortMusicSequencerInterface> Actor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static bool ReplicateMusicSequencerHit(const UObject* WorldContextObject, TScriptInterface<IFortMusicSequencerInterface> HitInterface, const AController* Instigator = nullptr);

protected:
	UFUNCTION()
	bool AddMusicSequencerActor(TScriptInterface<IFortMusicSequencerInterface> HitInterface);

	UFUNCTION()
	bool AddSequenceHitEvent(TScriptInterface<IFortMusicSequencerInterface> HitInterface, const AController* Instigator);

	UFUNCTION()
	void OnSequenceHitEventExpired(FMusicSequencerHitHandle ExpiredHandle);

	UFUNCTION()
	bool ProcessSequenceHitEvent(const FMusicSequencerHitEntry& Event);

	UPROPERTY(Transient, Replicated)
	FMusicSequencerHitArray MusicSequencerEventList;

	UPROPERTY(Transient, Replicated)
	TArray<USoundBase*> LoadedSoundsList;

	UPROPERTY(EditDefaultsOnly, Category="MusicSequencer")
	TArray<TSubclassOf<AActor>> SoundPreloadClassList;

};

