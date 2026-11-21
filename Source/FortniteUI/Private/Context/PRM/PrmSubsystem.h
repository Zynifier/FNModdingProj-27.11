// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "PrmSubsystem.generated.h"

class UMotdListViewModel;
class UPrmMotdPage;

UCLASS()
class FORTNITEUI_API UPrmSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UPrmMotdPage> BrMotd;

	UPROPERTY(Transient)
	TObjectPtr<UMotdListViewModel> DynamicMotds;

};

