// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimationBlueprintLibrary.h"

FVector UFortAnimationBlueprintLibrary::AlignVectorWithJoint(FVector Vector, const UMeshComponent* MeshComp, const UCustomCharacterPartAnimInstance* PartAnimInstance, FName JointName)
{
	return FVector();
}

void UFortAnimationBlueprintLibrary::ClothControllerDynamicParameterAdjustment(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, FName& InCharacterStateName, FClothParameters& InClothSettings, FVector& OutLinearVelocityScale, FClothParameters& OutClothSettings, const FVector& ClothUpAxis, const float OnGroundMovingAngularVelMax, const float OnGroundMovingFictitiousVelMax, const float LinVelScaleFwdBwdClamp, const float LinVelScaleUpDwnClamp)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerFindCharacterProperties(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, FClothControllerPropertiesMap& OutPropertiesMap, const float MinMovementSpeed, const float MinRidingMovementSpeed, const float MinUpwardVelocityThreshold, const float MaxFallingThreshold, const float HighRotationRateThreshold)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerFindCharacterState(FName& OutCharacterStateName, FClothStateLogicTree& InCharacterStateLogic, FClothControllerPropertiesMap& InCharacterProperties)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerFindParameters(FName InCharacterStateName, FClothControllerClothParameterMap& InClothParameterMap, FClothControllerWindParameterMap& InWindParameterMap, FClothParameters& OutClothSettings, FWindGustParameters& OutWindSettings)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerHelperScaleForPlayerMovement(FVector& InLinearVelocityScale, FVector& OutLinearVelocityScale, const float InPlayerForwardVector, const float InPlayerForwardVectorJump, const float InClothUpX, const float InClothUpZ)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerStaticFindCharacterState(FName& OutCharacterStateName, FClothControllerPropertiesMap& InCharacterProperties)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerWindGustControl(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, float DeltaTime, float GameTime, FWindGustParameters& InFWindGustParameters, FWindGustSettings& InWindGustLocalSettings, FVector& OutWindGustVector, FWindGustSettings& OutWindGustLocalSettings, const float RandomVectorTimeOffset, const float RandomVectorPerlinScale)
{
}

void UFortAnimationBlueprintLibrary::ClothControllerWindGustGenerator(FWindGustParameters& InWindGustParameters, FWindGustSettings& InWindGustLocalSettings, float& OutWindSpeed, FWindGustSettings& OutWindGustLocalSettings, const float DeltaTime, const float GameTimeSeconds, const float FinalGustStrengthInterpolationSpeed, const float WindSpeedMin, const float WindSpeedMax)
{
}

void UFortAnimationBlueprintLibrary::ForceTickAnimation(USkeletalMeshComponent* MeshComponent)
{
}

void UFortAnimationBlueprintLibrary::GetAlphaFromReferenceTransformDelta(float& AlphaOutput, float& RawOutput, const USkinnedMeshComponent* SkeletalMeshComponent, const FName BoneName, const FName BaseName, EAlphaFromDeltaTypes::Type DeltaComponentType, FVector2D InputRange, FVector2D OutputRange, FVector TwistAxis)
{
}

float UFortAnimationBlueprintLibrary::GetLoopedEmoteDuration(const FPrimaryAssetId& EmotePrimaryAssetId, int32 NumberOfLoops, AFortPlayerPawn* PlayerPawn)
{
	return float();
}

FRotator UFortAnimationBlueprintLibrary::GetPerlinRandomRotator(float GameTime, float TimeOffset, float PerlinScale, FRotator Frequency, FRotator Amplitude, FRotator Offset)
{
	return FRotator();
}

FVector UFortAnimationBlueprintLibrary::GetPerlinRandomVector(float GameTime, float TimeOffset, float PerlinScale, FVector Frequency, FVector Amplitude, FVector Offset)
{
	return FVector();
}

FRotator UFortAnimationBlueprintLibrary::GetRandomWindRotator(float GameTime, float TimeOffset, float PerlinScale, FRotator Frequency, FRotator Amplitude, FRotator Offset)
{
	return FRotator();
}

FVector UFortAnimationBlueprintLibrary::GetRandomWindVector(float GameTime, float TimeOffset, float PerlinScale, FVector Frequency, FVector Amplitude, FVector Offset)
{
	return FVector();
}

float UFortAnimationBlueprintLibrary::GetRelevantAnimTimeFromCachedData(FCachedAnimRelevancyData& InCachedAnimRelevancyData, UAnimInstance* InAnimInstance)
{
	return float();
}

float UFortAnimationBlueprintLibrary::GetRelevantAnimTimeRemainingFractionFromCachedData(FCachedAnimRelevancyData& InCachedAnimRelevancyData, UAnimInstance* InAnimInstance)
{
	return float();
}

float UFortAnimationBlueprintLibrary::GetRelevantAnimTimeRemainingFromCachedData(FCachedAnimRelevancyData& InCachedAnimRelevancyData, UAnimInstance* InAnimInstance)
{
	return float();
}

float UFortAnimationBlueprintLibrary::PlayAnimMontage(const AActor* Actor, const UAnimMontage* NewAnimMontage, const float InPlayRate, const FName StartSectionName)
{
	return float();
}

void UFortAnimationBlueprintLibrary::PlayerMovement(const UFortAnimInstance* AnimInstance, float XDotProductCoefficient, float YDotProductCoefficient, float ZDotProductCoefficient, bool bDrawDebug, float DebugScalar, float& XMovement, float& YMovement, float& ZMovement)
{
}

void UFortAnimationBlueprintLibrary::PlaySyncedMontage(UAnimInstance* LeaderAnimInstance, UAnimMontage* LeaderMontage, UAnimInstance* FollowerAnimInstance, UAnimMontage* FollowerMontage)
{
}

float UFortAnimationBlueprintLibrary::PoseReader(const USkeletalMeshComponent* MeshComponent, FName StartJoint, FName EndJoint, FName PoseJoint, float Angle, bool bDrawDebug)
{
	return float();
}

void UFortAnimationBlueprintLibrary::QueryPoseDeformation(const USkeletalMeshComponent* MeshComponent, FPoseDeformationQuery& PoseDeformationQuery)
{
}

void UFortAnimationBlueprintLibrary::QueryPoseDeformation_Arms(const USkeletalMeshComponent* MeshComponent, FPoseDeformationQuery_Arms& ArmsDeformationQuery)
{
}

void UFortAnimationBlueprintLibrary::SelectSimSpaceRotation(FRotator& SimSpaceRotation, bool& bUsingComponentSpace, bool& bInterpolating, float InterpSpeed, float InterpTolerance, float DeltaTime, float PawnSpeedMax, const UCustomCharacterPartAnimInstance* PartAnimInstance)
{
}

void UFortAnimationBlueprintLibrary::SetCurveInterpolationMode(UAnimSequence* Animation, FName CurveName, ERichCurveInterpMode InterpolationMode)
{
}

void UFortAnimationBlueprintLibrary::StopMontageIfCurrent(const AActor* Actor, const UAnimMontage* Montage, float OverrideBlendOutTime)
{
}

void UFortAnimationBlueprintLibrary::SyncMontages(const USkeletalMeshComponent* Leader, USkeletalMeshComponent* Follower)
{
}

void UFortAnimationBlueprintLibrary::UpdateAnimSpinner(FAnimSpinner& SpinInformation, float DeltaSeconds, float NewRotationRate)
{
}
