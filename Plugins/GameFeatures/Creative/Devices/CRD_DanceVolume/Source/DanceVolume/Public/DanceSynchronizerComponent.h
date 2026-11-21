// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DanceSynchronizerComponent.generated.h"

class AFortPlayerPawn;
class UAnimMontage;
class USkeletalMeshComponent;
enum class EDanceBeatSyncMode : uint8;

UENUM(BlueprintType)
enum class EDanceBeatSyncMode : uint8
{
	/** The emote's play rate or position will not be adjusted. */
	Off = 0 UMETA(DisplayName="Off"),
	/** Sync the emote play rate to a fixed tempo. */
	Tempo = 1 UMETA(DisplayName="Tempo"),
	/** Sync the emote play rate and position to a source of music. */
	Music = 2 UMETA(DisplayName="Music"),
};

USTRUCT(BlueprintType)
struct FDanceBeatInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DanceBeatInfo")
	float LengthBeats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DanceBeatInfo")
	float StartOffsetMs;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UDanceSynchronizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float CalculateDanceMontagePlayRate(const float CurrentTempo, const UAnimMontage* Montage, const FDanceBeatInfo& DanceBeatInfo);

	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetOwnerFortPlayerPawn();

	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetOwnerSkeletalMeshComponent();

	UFUNCTION(BlueprintPure)
	bool IsTempoSyncEnabled();

	UFUNCTION(BlueprintCallable)
	void SetBeatSyncMode(EDanceBeatSyncMode NewMode);

	UFUNCTION(BlueprintCallable)
	void SetDanceBeatInfo(const FDanceBeatInfo& NewDanceBeatInfo);

	UFUNCTION(BlueprintCallable)
	void SetTempo(float NewTempo);

	UFUNCTION(BlueprintCallable)
	void StopOwnerEmoteAudio();

protected:
	UPROPERTY(EditAnywhere, Category="DanceSynchronizerComponent")
	uint8 bShouldHalfOrDoubleTimeDances : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="DanceSynchronizerComponent", meta=(ExposeOnSpawn="TRUE"))
	FDanceBeatInfo BeatInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_SyncMode, Category="DanceSynchronizerComponent")
	EDanceBeatSyncMode SyncMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="DanceSynchronizerComponent", meta=(EditCondition="SyncMode == EDanceBeatSyncMode::Tempo", ExposeOnSpawn="TRUE"))
	float Tempo;

private:
	UFUNCTION()
	void OnRep_SyncMode();

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> OwnerPlayerPawn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> OwnerMeshComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> LeaderMeshComponent;

};

