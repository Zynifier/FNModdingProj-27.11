// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_TowerSentinelPack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_TowerSentinelPack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Tower Sentinel Pack|Physics|Functions")
	FVector CalculateCompLinearAccScale();

	UFUNCTION(BlueprintPure, Category="Tower Sentinel Pack|Physics|Functions")
	FVector CalculateCompLinearVelScale();

	UFUNCTION(BlueprintPure, Category="Tower Sentinel Pack|Physics|Functions")
	FVector CalculateFinalGravity();

	UFUNCTION(BlueprintPure, Category="Tower Sentinel Pack|Physics|Functions")
	float CalculateIsEmotingAlpha();

	UFUNCTION(BlueprintPure, Category="Tower Sentinel Pack|Physics|Functions")
	float CalculateJumpingAlpha();

	UFUNCTION(BlueprintPure, Category="Tower Sentinel Pack|Physics|Functions")
	FVector CalculateWindVector();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Body Joints|Functions")
	void UpdateBodyJoints();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Physics|Functions")
	void UpdateBoneRotators();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Physics|Functions")
	void UpdateCompLinearScales();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Physics|Functions")
	void UpdateFinalGravity();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Physics|Functions")
	void UpdateIsEmotingAlpha();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Physics|Functions")
	void UpdateJumpingAlpha();

	UFUNCTION(BlueprintCallable, Category="Tower Sentinel Pack|Physics|Functions")
	void UpdateWindVector();

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Physics|Properties")
	FVector WindVector;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Physics|Properties")
	FVector FinalGravity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Physics|Properties")
	float IsEmotingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Physics|Properties")
	float JumpingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Physics|Properties")
	FVector CompLinearVelScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Physics|Properties")
	FVector CompLinearAccScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	float SkydivingForceScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	FVector NonSkydivingWindVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	FName DanceGravityBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	FName DanceGravityBaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	float DanceGravityInflectionAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	float IsEmotingAlphaMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	float IsEmotingAlphaMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	float JumpingAlphaMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	float JumpingAlphaMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	FVector SkydivingCompLinearScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Physics|Magic Numbers")
	FVector NonSkydivingCompLinearScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator IndexA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator IndexB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator IndexC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexA_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexA_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexA_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector IndexA_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector IndexA_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexB_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexB_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexB_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector IndexB_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector IndexB_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexC_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexC_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator IndexC_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector IndexC_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector IndexC_Max;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator MiddleA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator MiddleB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator MiddleC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleA_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleA_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleA_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector MiddleA_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector MiddleA_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleB_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleB_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleB_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector MiddleB_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector MiddleB_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleC_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleC_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator MiddleC_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector MiddleC_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector MiddleC_Max;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator RingA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator RingB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator RingC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingA_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingA_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingA_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector RingA_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector RingA_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingB_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingB_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingB_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector RingB_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector RingB_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingC_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingC_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator RingC_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector RingC_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector RingC_Max;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator PinkyA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator PinkyB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Bones|Properties")
	FRotator PinkyC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyA_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyA_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyA_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector PinkyA_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector PinkyA_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyB_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyB_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyB_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector PinkyB_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector PinkyB_Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyC_Amplitudes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyC_Frequencies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FRotator PinkyC_Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector PinkyC_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tower Sentinel Pack|Bones|Magic Numbers")
	FVector PinkyC_Max;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector BodyRootTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator BodyRootRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector PelvisTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator PelvisRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector RootTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator RootRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector ThighLTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator ThighLRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector ThighRTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator ThighRRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector CalfLTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator CalfLRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector CalfRTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator CalfRRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector Spine01Tran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator Spine01Rot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector Spine02Tran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator Spine02Rot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector Spine03Tran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator Spine03Rot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector Spine04Tran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator Spine04Rot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector Spine05Tran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator Spine05Rot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector ClavicleLTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator ClavicleLRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector ClavicleRTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator ClavicleRRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector UpperarmLTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator UpperarmLRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector UpperarmRTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator UpperarmRRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector LowerarmLTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator LowerarmLRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FVector LowerarmRTran;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tower Sentinel Pack|Joints|Properties")
	FRotator LowerarmRRot;

};

