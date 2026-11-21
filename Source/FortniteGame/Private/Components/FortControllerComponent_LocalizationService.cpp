// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_LocalizationService.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_LocalizationService::OnRep_LocalizationDocument()
{
}

void UFortControllerComponent_LocalizationService::ServerUpdateLocale_Implementation(const FString& InLocale)
{
}

void UFortControllerComponent_LocalizationService::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_LocalizationService, LocalizationDocument);
}
