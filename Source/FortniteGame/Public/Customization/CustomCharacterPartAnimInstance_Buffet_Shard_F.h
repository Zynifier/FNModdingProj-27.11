// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance_Buffet_F.h"
#include "CustomCharacterPartAnimInstance_Buffet_Shard_F.generated.h"

USTRUCT(BlueprintType)
struct FBuffetWaveVectorInput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Wave Vector")
	FRotator Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Wave Vector")
	FRotator Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Wave Vector")
	FRotator Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Wave Vector")
	bool bUseNoise;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Wave Vector")
	FVector Min;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Wave Vector")
	FVector Max;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Buffet_Shard_F : public UCustomCharacterPartAnimInstance_Buffet_F
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|Shard|AnimGraph|Ambient Motion")
	FVector floatA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|Shard|AnimGraph|Ambient Motion")
	FVector floatB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|Shard|AnimGraph|Skirt")
	float skirtMidJntConstraintAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Shard|Inputs|Ambient Motion")
	FBuffetWaveVectorInput WaveA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Shard|Inputs|Ambient Motion")
	FBuffetWaveVectorInput WaveB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Shard|Inputs|Skirt|Magic Numbers")
	float PawnVelocityZLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Shard|Inputs|Skirt|Magic Numbers")
	float PawnYawRotationRateLimit;

};

