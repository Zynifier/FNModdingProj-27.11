// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Curves/RealCurve.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "UObject/PrimaryAssetId.h"
#include "FortAnimationBlueprintLibrary.generated.h"

class AActor;
class AFortPlayerPawn;
class UAnimInstance;
class UAnimMontage;
class UAnimSequence;
class UCustomCharacterPartAnimInstance;
class UFortAnimInstance;
class UMeshComponent;
class USkeletalMeshComponent;
class USkinnedMeshComponent;

UENUM()
namespace EAlphaFromDeltaTypes
{
	enum Type
	{
		TranslationX = 0,
		TranslationY = 1,
		TranslationZ = 2,
		Scale = 3,
		ScaleX = 4,
		ScaleY = 5,
		ScaleZ = 6,
		EulerX = 7,
		EulerY = 8,
		EulerZ = 9,
		QuaternionTwist = 10,
	};
}

USTRUCT(BlueprintType)
struct FAnimSpinner
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="AnimSpinner")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AnimSpinner")
	FVector RotationAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AnimSpinner")
	float BaseRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AnimSpinner")
	float RotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AnimSpinner")
	float InterpolationRateSpeedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AnimSpinner")
	float InterpolationRateSlowDown;

	UPROPERTY(BlueprintReadOnly, Category="AnimSpinner")
	float RotationAngle;

};

USTRUCT(BlueprintType)
struct FClothParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	FVector LinearVelocityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	float AngularVelocityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	float FictitiousAngularScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	FVector GravityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	FVector2D DragCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	FVector2D LiftCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothParameters")
	FName JointName;

};

USTRUCT(BlueprintType)
struct FClothControllerClothParameterMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothControllerClothParameterMap")
	TMap<FName, FClothParameters> Map;

};

USTRUCT(BlueprintType)
struct FClothControllerPropertiesMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothControllerPropertiesMap")
	TMap<FName, bool> Map;

};

USTRUCT(BlueprintType)
struct FWindGustParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MinTimeBetweenGusts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MaxTimeBetweenGusts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MinGustStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MaxGustStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MinGustDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MaxGustDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float WindTurbulenceScalarA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float WindTurbulenceScalarB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MinUpInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MaxUpInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MinDownInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	float MaxDownInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	FVector WindFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	FVector WindAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustParameters")
	FVector WindOffset;

};

USTRUCT(BlueprintType)
struct FClothControllerWindParameterMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothControllerWindParameterMap")
	TMap<FName, FWindGustParameters> Map;

};

USTRUCT(BlueprintType)
struct FClothCoreSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	FVector2D EdgeStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	FVector2D BendingStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	FVector2D AreaStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	FVector2D TetherStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	float CollisionThickness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	float FrictionCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	float SelfCollisionThickness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	float DampingCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	float LocalDampingCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	FVector2D AnimDriveStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	FVector2D AnimDriveDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	int32 NumberIterations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothCoreSettings")
	int32 NumberSubsteps;

};

USTRUCT(BlueprintType)
struct FPropertyStatePair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PropertyStatePair")
	FName StateName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PropertyStatePair")
	int32 BitSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PropertyStatePair")
	int32 BitMask;

};

USTRUCT(BlueprintType)
struct FClothStateLogicTree
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothStateLogicTree")
	TMap<FName, int32> PropertyNameToBitFlagMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClothStateLogicTree")
	TArray<FPropertyStatePair> PropertyFlagsToStateNameTable;

};

USTRUCT(BlueprintType)
struct FMapRangeClamped_Ranges
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MapRangeClamped_Ranges")
	float InRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MapRangeClamped_Ranges")
	float InRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MapRangeClamped_Ranges")
	float OutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MapRangeClamped_Ranges")
	float OutRangeB;

};

USTRUCT(BlueprintType)
struct FPoseDeformationQuery
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery")
	FName StartJoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery")
	FName EndJoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery")
	FName PoseJoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery")
	float Angle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery")
	bool bDrawDebug;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQuery")
	float Alpha;

};

USTRUCT(BlueprintType)
struct FPoseDeformationQueryResults_Arms
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmUpR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmForwardL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmForwardR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmBackL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmBackR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmForwardUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmForwardUpR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmForwardDownL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQueryResults_Arms")
	float ArmForwardDownR;

};

USTRUCT(BlueprintType)
struct FPoseDeformationQuery_Arms
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQueryResults_Arms QueryResults;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmUpL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmUpR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmForwardL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmForwardR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmBackL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmBackR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmForwardUpL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmForwardUpR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmForwardDownL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoseDeformationQuery_Arms")
	FPoseDeformationQuery ArmForwardDownR;

};

USTRUCT(BlueprintType)
struct FWindGustSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustSettings")
	float ElapsedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustSettings")
	float TimeBetweenGusts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustSettings")
	float GustStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustSettings")
	float GustDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WindGustSettings")
	float FinalGustStrengthLocal;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAnimationBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static FVector AlignVectorWithJoint(FVector Vector, const UMeshComponent* MeshComp, const UCustomCharacterPartAnimInstance* PartAnimInstance, FName JointName);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerDynamicParameterAdjustment(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, UPARAM(ref, DisplayName="Character State") FName& InCharacterStateName, UPARAM(ref, DisplayName="Cloth Settings") FClothParameters& InClothSettings, UPARAM(DisplayName="Linear Velocity Scale") FVector& OutLinearVelocityScale, UPARAM(DisplayName="Cloth Settings") FClothParameters& OutClothSettings, const FVector& ClothUpAxis, const float OnGroundMovingAngularVelMax, const float OnGroundMovingFictitiousVelMax, const float LinVelScaleFwdBwdClamp, const float LinVelScaleUpDwnClamp);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerFindCharacterProperties(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, FClothControllerPropertiesMap& OutPropertiesMap, const float MinMovementSpeed = 20.000000f, const float MinRidingMovementSpeed = 20.000000f, const float MinUpwardVelocityThreshold = 50.000000f, const float MaxFallingThreshold = 2600.000000f, const float HighRotationRateThreshold = 50.000000f);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerFindCharacterState(UPARAM(DisplayName="Character State") FName& OutCharacterStateName, UPARAM(ref, DisplayName="Character State Logic") FClothStateLogicTree& InCharacterStateLogic, UPARAM(ref, DisplayName="Character Properties") FClothControllerPropertiesMap& InCharacterProperties);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerFindParameters(UPARAM(DisplayName="Character State") FName InCharacterStateName, UPARAM(ref, DisplayName="Cloth Parameters") FClothControllerClothParameterMap& InClothParameterMap, UPARAM(ref, DisplayName="Wind Parameters") FClothControllerWindParameterMap& InWindParameterMap, UPARAM(DisplayName="Cloth Settings") FClothParameters& OutClothSettings, UPARAM(DisplayName="Wind Settings") FWindGustParameters& OutWindSettings);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerHelperScaleForPlayerMovement(UPARAM(ref) FVector& InLinearVelocityScale, UPARAM(DisplayName="Linear Velocity Scale") FVector& OutLinearVelocityScale, const float InPlayerForwardVector, const float InPlayerForwardVectorJump, const float InClothUpX, const float InClothUpZ);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerStaticFindCharacterState(UPARAM(DisplayName="Character State") FName& OutCharacterStateName, UPARAM(ref, DisplayName="Character Properties") FClothControllerPropertiesMap& InCharacterProperties);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerWindGustControl(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, float DeltaTime, float GameTime, UPARAM(ref, DisplayName="Wind Gust Parameters") FWindGustParameters& InFWindGustParameters, UPARAM(ref, DisplayName="Wind Gust Local Settings") FWindGustSettings& InWindGustLocalSettings, UPARAM(DisplayName="Wind Gust") FVector& OutWindGustVector, UPARAM(DisplayName="Wind Gust Local Settings") FWindGustSettings& OutWindGustLocalSettings, const float RandomVectorTimeOffset = 0.000000f, const float RandomVectorPerlinScale = 1.000000f);

	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerWindGustGenerator(UPARAM(ref, DisplayName="Wind Gust Parameters") FWindGustParameters& InWindGustParameters, UPARAM(ref, DisplayName="Wind Gust Local Settings") FWindGustSettings& InWindGustLocalSettings, UPARAM(DisplayName="Wind Speed") float& OutWindSpeed, UPARAM(DisplayName="Wind Gust Local Settings") FWindGustSettings& OutWindGustLocalSettings, const float DeltaTime, const float GameTimeSeconds, const float FinalGustStrengthInterpolationSpeed = 5.000000f, const float WindSpeedMin = 0.010000f, const float WindSpeedMax = 2.000000f);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ForceTickAnimation(USkeletalMeshComponent* MeshComponent);

	UFUNCTION(BlueprintPure, Category="Alpha Utility")
	static void GetAlphaFromReferenceTransformDelta(float& AlphaOutput, float& RawOutput, const USkinnedMeshComponent* SkeletalMeshComponent, const FName BoneName, const FName BaseName, EAlphaFromDeltaTypes::Type DeltaComponentType = EAlphaFromDeltaTypes::QuaternionTwist, FVector2D InputRange = FVector2D(0.000, 1.000), FVector2D OutputRange = FVector2D(0.000, 1.000), FVector TwistAxis = FVector(1.000000, 0.000000, 0.000000));

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static float GetLoopedEmoteDuration(const FPrimaryAssetId& EmotePrimaryAssetId, int32 NumberOfLoops, AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static FRotator GetPerlinRandomRotator(float GameTime, float TimeOffset, float PerlinScale, FRotator Frequency, FRotator Amplitude, FRotator Offset);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static FVector GetPerlinRandomVector(float GameTime, float TimeOffset, float PerlinScale, FVector Frequency, FVector Amplitude, FVector Offset);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static FRotator GetRandomWindRotator(float GameTime, float TimeOffset, float PerlinScale, FRotator Frequency, FRotator Amplitude, FRotator Offset);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static FVector GetRandomWindVector(float GameTime, float TimeOffset, float PerlinScale, FVector Frequency, FVector Amplitude, FVector Offset);

	UFUNCTION(BlueprintPure, Category="State Machine")
	static float GetRelevantAnimTimeFromCachedData(UPARAM(ref) FCachedAnimRelevancyData& InCachedAnimRelevancyData, UAnimInstance* InAnimInstance);

	UFUNCTION(BlueprintPure, Category="State Machine")
	static float GetRelevantAnimTimeRemainingFractionFromCachedData(UPARAM(ref) FCachedAnimRelevancyData& InCachedAnimRelevancyData, UAnimInstance* InAnimInstance);

	UFUNCTION(BlueprintPure, Category="State Machine")
	static float GetRelevantAnimTimeRemainingFromCachedData(UPARAM(ref) FCachedAnimRelevancyData& InCachedAnimRelevancyData, UAnimInstance* InAnimInstance);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities", meta=(DefaultToSelf="Actor"))
	static float PlayAnimMontage(const AActor* Actor, const UAnimMontage* NewAnimMontage, const float InPlayRate = 1.000000f, const FName StartSectionName = NAME_None);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void PlayerMovement(const UFortAnimInstance* AnimInstance, float XDotProductCoefficient, float YDotProductCoefficient, float ZDotProductCoefficient, bool bDrawDebug, float DebugScalar, float& XMovement, float& YMovement, float& ZMovement);

	UFUNCTION(BlueprintCallable, Category="Animation|Sync")
	static void PlaySyncedMontage(UAnimInstance* LeaderAnimInstance, UAnimMontage* LeaderMontage, UAnimInstance* FollowerAnimInstance, UAnimMontage* FollowerMontage);

	UFUNCTION(BlueprintCallable, Category="Animation|PSD")
	static float PoseReader(const USkeletalMeshComponent* MeshComponent, FName StartJoint, FName EndJoint, FName PoseJoint, float Angle, bool bDrawDebug = false);

	UFUNCTION(BlueprintCallable, Category="Animation|PSD")
	static void QueryPoseDeformation(const USkeletalMeshComponent* MeshComponent, UPARAM(ref) FPoseDeformationQuery& PoseDeformationQuery);

	UFUNCTION(BlueprintCallable, Category="Animation|PSD")
	static void QueryPoseDeformation_Arms(const USkeletalMeshComponent* MeshComponent, UPARAM(ref) FPoseDeformationQuery_Arms& ArmsDeformationQuery);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void SelectSimSpaceRotation(UPARAM(ref) FRotator& SimSpaceRotation, UPARAM(ref) bool& bUsingComponentSpace, UPARAM(ref) bool& bInterpolating, float InterpSpeed = 9.000000f, float InterpTolerance = 1.000000f, float DeltaTime = 0.000000f, float PawnSpeedMax = 20.000000f, const UCustomCharacterPartAnimInstance* PartAnimInstance = nullptr);

	UFUNCTION(BlueprintCallable, Category="Animation|Modifier")
	static void SetCurveInterpolationMode(UAnimSequence* Animation, FName CurveName, ERichCurveInterpMode InterpolationMode);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities", meta=(DefaultToSelf="Actor"))
	static void StopMontageIfCurrent(const AActor* Actor, const UAnimMontage* Montage, float OverrideBlendOutTime = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void SyncMontages(const USkeletalMeshComponent* Leader, USkeletalMeshComponent* Follower);

	UFUNCTION(BlueprintCallable, Category="Anim Spinner")
	static void UpdateAnimSpinner(UPARAM(ref) FAnimSpinner& SpinInformation, float DeltaSeconds, float NewRotationRate = 1.000000f);

};

