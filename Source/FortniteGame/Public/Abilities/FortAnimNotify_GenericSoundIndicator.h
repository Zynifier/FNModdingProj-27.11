// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "FortSoundCameraLensEffect.h"
#include "FortTeamEnum.h"
#include "FortAnimNotify_GenericSoundIndicator.generated.h"

class USoundBase;

UCLASS(EditInlineNew, HideCategories=("Object", "Object"), meta=(DisplayName="Generic Sound Indicator"))
class UFortAnimNotify_GenericSoundIndicator : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Ability")
	bool bTryUsingOwnerSoundIndicator;

	UPROPERTY(EditAnywhere, Category="Ability")
	TSoftObjectPtr<USoundBase> BaseSound;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(EditCondition="!bTryUsingOwnerSoundIndicator"))
	float MaxAudibleDistance;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(EditCondition="!bTryUsingOwnerSoundIndicator"))
	EFortSoundIndicatorTypes IndicatorType;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(EditCondition="!bTryUsingOwnerSoundIndicator"))
	bool bIgnoreForLocalPlayer;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(EditCondition="!bTryUsingOwnerSoundIndicator"))
	TArray<TEnumAsByte<EFortTeamAffiliation::Type>> ShowAffiliations;

};

