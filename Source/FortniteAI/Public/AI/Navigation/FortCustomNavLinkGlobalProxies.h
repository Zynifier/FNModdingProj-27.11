// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavigationTypes.h"
#include "NavLinkCustomInterface.h"
#include "UObject/NoExportTypes.h"
#include "FortCustomNavLinkGlobalProxies.generated.h"

class UObject;

UCLASS(MinimalAPI)
class UFortCustomNavLinkGlobalProxy : public UObject, public INavLinkCustomInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FNavLinkId LinkID;

	UPROPERTY(Transient)
	TObjectPtr<UObject> Owner;

};

UCLASS(MinimalAPI)
class UFortClamberLinkGlobalProxy : public UFortCustomNavLinkGlobalProxy
{
	GENERATED_BODY()

};

