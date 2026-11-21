// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Curves/CurveVector.h"
#include "Curves/RichCurve.h"
#include "Math/MathFwd.h"
#include "FortAudioCurveVector.generated.h"

class UCurveFloat;
enum class EVectorCurveFloat : uint8;
enum class EVectorCurveType : uint8;

UENUM(BlueprintType)
enum class EVectorCurveFloat : uint8
{
	VectorCurve_X = 0,
	VectorCurve_Y = 1,
	VectorCurve_Z = 2,
};

UENUM(BlueprintType)
enum class EVectorCurveType : uint8
{
	Original = 0,
	Modified = 1,
};

USTRUCT()
struct FAudioCurveInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FRichCurve Curve;

};

UCLASS(DefaultToInstanced, BlueprintType)
class UFortAudioCurveVector : public UCurveVector
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AudioCurveVector")
	void ExportCurves(EVectorCurveType CurveType);

	UFUNCTION(BlueprintPure, Category="AudioCurveVector")
	FVector GetAudioCurveVectorValue(const float InTime) const;

	UFUNCTION(BlueprintPure, Category="AudioCurveVector")
	float GetLargestMaxDistance() const;

	UFUNCTION(BlueprintCallable, Category="AudioCurveVector")
	void ImportAttenuationCurve(EVectorCurveFloat Element, UPARAM(ref) FRuntimeFloatCurve& Curve, float MaxDistance);

	UFUNCTION(BlueprintCallable, Category="AudioCurveVector")
	void ImportFloatCurve(EVectorCurveFloat Element, UCurveFloat* Curve);

	UFUNCTION(BlueprintCallable, Category="AudioCurveVector")
	void InitializeAudioCurveVector();

	UFUNCTION(BlueprintCallable, Category="AudioCurveVector")
	void SetActiveCurves(EVectorCurveType CurveType);

	virtual TArray<FRichCurveEditInfoConst> GetCurves() const override;

	virtual TArray<FRichCurveEditInfo> GetCurves() override;

	virtual bool IsValidCurve(FRichCurveEditInfo CurveInfo) override;

private:
	UPROPERTY()
	TObjectPtr<UCurveFloat> ExternalCurves[3];

	UPROPERTY()
	TArray<FAudioCurveInfo> AudioCurves;

	UPROPERTY()
	TArray<FAudioCurveInfo> OriginalAudioCurves;

	UPROPERTY()
	TArray<FAudioCurveInfo> ModifiedAudioCurves;

};

