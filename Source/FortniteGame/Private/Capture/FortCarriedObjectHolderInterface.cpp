// Copyright Epic Games, Inc. All Rights Reserved.

#include "Capture/FortCarriedObjectHolderInterface.h"

bool IFortCarriedObjectHolderInterface::CanHoldObject(AActor* CarriableObject) const
{
	return false;
}

USceneComponent* IFortCarriedObjectHolderInterface::GetAttachmentComponent(FName SocketName) const
{
	return nullptr;
}

void IFortCarriedObjectHolderInterface::GetCarriedObjectAttachmentInfo(FCarriedObjectAttachmentInfo& OutAttachInfo) const
{
}

void IFortCarriedObjectHolderInterface::OnCarriedObjectAttach(AActor* AttachedObject)
{
}

void IFortCarriedObjectHolderInterface::OnCarriedObjectDetach(AActor* DetachedObject)
{
}
