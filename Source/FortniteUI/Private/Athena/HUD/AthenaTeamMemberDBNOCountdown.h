// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaTeamMemberDBNOCountdown.generated.h"

class AFortPlayerStateAthena;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaTeamMemberDBNOCountdown : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerState(AFortPlayerStateAthena* InPlayerState);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Timer;

};

