// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LiveLinkTypes.h"
#include "FortAnimTypes.generated.h"

class UAnimSequenceBase;

UENUM(BlueprintType)
enum class EFortCardinalDirection : uint8
{
	North = 0,
	East = 1,
	South = 2,
	West = 3,
};

UENUM(BlueprintType)
enum class EFortFacialAnimTypes : uint8
{
	Default = 0,
	// this is default behavior of game

	FaceOnly = 1,
	// The animation is only applied to the face and neck motion is ignored

	FullHead = 2,
	// The animation is applied to the entire head including neck

	FromAmplitude = 3,
	// The animation is computed from voice amplitude 

	Max = 4,
};

UENUM(BlueprintType)
enum class EFortHandIKOverrideType : uint8
{
	// Use default behavior, which is usually to control hand IK via curves

	UseDefault = 0,
	// Override default behavior and always use FK

	ForceFK = 1,
	// Override default behavior and always use IK

	ForceIK = 2,
	// Override default behavior and always use FK without blending

	ForceFKSnap = 3,
};

UENUM(BlueprintType)
enum class EFortPlayerAnimBodyType : uint8
{
	Small = 0,
	Medium = 1,
	Large = 2,
	All = 3,
};

UENUM(BlueprintType)
enum class EGliderType : uint8
{
	HangGlider = 0,
	Umbrella = 1,
	Surfing = 2,
	SurfingSimple = 3,
	Cape = 4,
	Stairs = 5,
	NoGlider = 6,
};

UENUM(BlueprintType)
enum class EPlaneDirection : uint8
{
	Center = 0,
	Right = 1,
	Left = 2,
	Up = 3,
	Down = 4,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortAnimInput_Facial
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FFortAnimInput_Facial")
	FLiveLinkSubjectName SubjectName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FFortAnimInput_Facial")
	EFortFacialAnimTypes CurrentAnimType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FFortAnimInput_Facial")
	bool bCurvesOnly;

};

USTRUCT(BlueprintType)
struct FFortAnimPlayrateRange
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAnimPlayrateRange")
	float MinPlayrate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAnimPlayrateRange")
	float MaxPlayrate;

};

USTRUCT(BlueprintType)
struct FFortCachedFloatCurve
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Curve Settings")
	FName CurveName;

};

USTRUCT(BlueprintType)
struct FFortDirectionalAnimRef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDirectionalAnimRef")
	TObjectPtr<UAnimSequenceBase> NorthAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDirectionalAnimRef")
	TObjectPtr<UAnimSequenceBase> SouthAnimLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDirectionalAnimRef")
	TObjectPtr<UAnimSequenceBase> SouthAnimRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDirectionalAnimRef")
	TObjectPtr<UAnimSequenceBase> EastAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDirectionalAnimRef")
	TObjectPtr<UAnimSequenceBase> WestAnim;

};

USTRUCT(BlueprintType)
struct FFortDistanceCurve : public FFortCachedFloatCurve
{
	GENERATED_BODY()

};

