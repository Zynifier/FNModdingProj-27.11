// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ActorComponent_ReplicatedParamHelper.h"
#include "Net/UnrealNetwork.h"

void UActorComponent_ReplicatedParamHelper::GetParamAsBool(const FGameplayTag ParamTag, bool& Value, bool& bValidParam)
{
}

void UActorComponent_ReplicatedParamHelper::GetParamAsFloat(const FGameplayTag ParamTag, float& Value, bool& bValidParam)
{
}

void UActorComponent_ReplicatedParamHelper::GetParamAsInt(const FGameplayTag ParamTag, int32& Value, bool& bValidParam)
{
}

void UActorComponent_ReplicatedParamHelper::ResendAllParamChangedEvents()
{
}

bool UActorComponent_ReplicatedParamHelper::SendParamAsBool(const FGameplayTag& ParamTag, bool Value, bool bForceParamDirty)
{
	return false;
}

bool UActorComponent_ReplicatedParamHelper::SendParamAsFloat(const FGameplayTag& ParamTag, float Value, bool bForceParamDirty)
{
	return false;
}

bool UActorComponent_ReplicatedParamHelper::SendParamAsInt(const FGameplayTag& ParamTag, int32 Value, bool bForceParamDirty)
{
	return false;
}

void UActorComponent_ReplicatedParamHelper::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UActorComponent_ReplicatedParamHelper, ParamFloatsArray);
	DOREPLIFETIME(UActorComponent_ReplicatedParamHelper, ParamIntegersArray);
	DOREPLIFETIME(UActorComponent_ReplicatedParamHelper, ParamBoolsArray);
}
