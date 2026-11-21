// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingFeedback.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingFeedback : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DestroyWidget();

};

