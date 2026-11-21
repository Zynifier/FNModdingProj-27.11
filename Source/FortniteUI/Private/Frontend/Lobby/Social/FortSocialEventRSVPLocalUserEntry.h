// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortLocalUserEntry.h"
#include "FortSocialEventRSVPLocalUserEntry.generated.h"

class UFortSocialEventRSVPWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialEventRSVPLocalUserEntry : public UFortLocalUserEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialEventRSVPWidget> BuffetInfo;

};

