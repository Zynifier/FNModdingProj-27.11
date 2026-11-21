// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FabricFloatProvider.h"
#include "FabricFloatProviderLFO.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EFabricWaveShape : uint8
{
	Sine = 0,
	Triangle = 1,
	Saw = 2,
	Square = 3,
	RandomStepped = 4,
	RandomSmooth = 5,
};

UENUM(BlueprintType)
enum class EFabricWaveSyncType : uint8
{
	/** The LFO runs on a set frequency disconnected from the music */
	Free = 0,
	/** The LFO runs connected to the music with a defined beat duration and offset */
	BeatSync = 1,
};

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricLFOGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricLFOGenerator")
	EFabricWaveShape WaveShape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricLFOGenerator")
	float Minimum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricLFOGenerator")
	float Maximum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricLFOGenerator")
	float Shape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricLFOGenerator")
	int32 InitialSeed;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricFloatProviderWave : public UFabricFloatProviderBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddPreviewDisplayMesh(UStaticMeshComponent* Mesh);

	UFUNCTION(BlueprintCallable)
	void ClearPreviewDisplayMeshes();

	UFUNCTION(BlueprintPure)
	float GetCurrentFreePhase() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentPhase() const;

	UFUNCTION(BlueprintPure)
	TArray<UStaticMeshComponent*> GetPreviewDisplayMeshes();

	UFUNCTION(BlueprintPure)
	int32 GetRandomSeed() const;

	UFUNCTION(BlueprintCallable)
	void RemovePreviewDisplayMesh(UStaticMeshComponent* Mesh);

	UFUNCTION(BlueprintCallable)
	void SetFreePhase(float InFreePhase);

	UFUNCTION(BlueprintCallable)
	void SetRandomSeedByGuid(const FGuid& InRandomGuid);

protected:
	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString WaveShapeParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString FreeHzParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString MinParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString MaxParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString BeatDurationParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString BeatOffsetParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString ShapeParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	FString StyleParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	int32 PhaseCPDIndex;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderWave")
	int32 ValueCPDIndex;

private:
	UPROPERTY(Transient, Export)
	TSet<TWeakObjectPtr<UStaticMeshComponent>> PreviewDisplayMeshes;

};

