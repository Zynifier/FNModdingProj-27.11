// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Sound/FortFeedbackManager.h"
#include "FortAnimNotify_PlayFeedbackLine.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Play Feedback Line"))
class UFortAnimNotify_PlayFeedbackLine : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FFortFeedbackHandle Event;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	bool bAllowReplication;

};

