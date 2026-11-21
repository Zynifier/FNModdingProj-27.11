// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Grilled_Cheese_Pack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Grilled_Cheese_Pack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	float SpinFNC(float Speed, float InitialValue = 0.000000f);

	UFUNCTION(BlueprintCallable)
	void UpdateCracks();

	UFUNCTION(BlueprintCallable)
	void UpdateCrackSpinLogic(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void UpdateFloatCubes();

	UFUNCTION(BlueprintCallable)
	void UpdateSpinSettings();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	bool ActiveKill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	float crackCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	float crackSpin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	float crackSpinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	float interpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	bool isCrackCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	float killCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	TArray<float> killCrackArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	float onCrackSpinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FRotator crackRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FRotator Spinning_Rotator_00;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FRotator Spinning_Rotator_01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FRotator Spinning_Rotator_02;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FRotator Spinning_Rotator_03;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FVector crackTran;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FVector Cube_Float_A;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Grilled_Cheese_Pack")
	FVector Cube_Float_B;

};

