// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortControllerComponent_CreativeFunctionalTest.h"
#include "Net/UnrealNetwork.h"

bool UFortControllerComponent_CreativeFunctionalTest::CanInteractWithActor(AActor* ActorToUse, UFortControllerComponent_Interaction* InteractComponent) const
{
	return false;
}

void UFortControllerComponent_CreativeFunctionalTest::SetFunctionalTest(ACreativeFunctionalTest* FunctionalTest)
{
}

bool UFortControllerComponent_CreativeFunctionalTest::TryInteractUseForActor(AActor* ActorToUse, UFortControllerComponent_Interaction* InteractComponent)
{
	return false;
}

void UFortControllerComponent_CreativeFunctionalTest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_CreativeFunctionalTest, FunctionalTest);
}
