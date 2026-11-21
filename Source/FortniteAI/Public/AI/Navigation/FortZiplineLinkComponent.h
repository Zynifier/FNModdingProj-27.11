// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "NavLinkCustomComponent.h"
#include "FortZiplineLinkComponent.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAI_API UFortZiplineLinkComponent : public UNavLinkCustomComponent
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="LinkGeneration")
	bool bShowNavLinkDebug;
#endif

protected:
	UFUNCTION()
	void OnZiplineStateChanged(const bool bIsZiplining, AFortPlayerPawn* FortPlayerPawn);

	UPROPERTY(EditAnywhere, Category="LinkGeneration")
	FVector LinkOffsetFromSplineStart;

	UPROPERTY(EditAnywhere, Category="LinkGeneration")
	FVector LinkOffsetFromSplineEnd;

	UPROPERTY(EditAnywhere, Category="LinkGeneration")
	bool bOverrideSnapRadius;

	UPROPERTY(EditAnywhere, Category="LinkGeneration", meta=(ClampMin="1.0", DisplayAfter="bOverrideSnapRadius", EditCondition="bOverrideSnapRadius", UIMin="1.0"))
	float SnapRadiusOverride;

	UPROPERTY(EditAnywhere, Category="LinkGeneration")
	bool bOverrideSnapHeight;

	UPROPERTY(EditAnywhere, Category="LinkGeneration", meta=(ClampMin="1.0", DisplayAfter="bOverrideSnapHeight", EditCondition="bOverrideSnapHeight", UIMin="1.0"))
	float SnapHeightOverride;

};

