// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "FortAutorunLockZoneButton.generated.h"

class UFortAutorunLockZone;

UCLASS()
class UFortAutorunLockZoneButton : public UBacchusHUDElement
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAutorunLockZone> AutorunLockZone;

};

