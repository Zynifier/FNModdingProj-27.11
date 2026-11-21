// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Animation/FortAnimTypes.h"
#include "FortAnimNotifyState_EmoteRetargeting.generated.h"

USTRUCT(BlueprintType)
struct FEmoteRetargetingNotifyParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EmoteRetargeting")
	EFortPlayerAnimBodyType BodyTypeToAffect;

	UPROPERTY(EditAnywhere, Category="EmoteRetargeting")
	EFortHandIKOverrideType LeftHandIK;

	UPROPERTY(EditAnywhere, Category="EmoteRetargeting")
	EFortHandIKOverrideType RightHandIK;

};

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_EmoteRetargeting : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EmoteRetargeting")
	TArray<FEmoteRetargetingNotifyParameters> EmoteParameters;

};

