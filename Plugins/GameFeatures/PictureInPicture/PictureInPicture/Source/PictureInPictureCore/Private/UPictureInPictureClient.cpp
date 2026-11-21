// Copyright Epic Games, Inc. All Rights Reserved.

#include "UPictureInPictureClient.h"

void UPictureInPictureClient::BeginLogin(UObject* InWorldContext)
{
}

void UPictureInPictureClient::CheckLogin(UObject* InWorldContext)
{
}

void UPictureInPictureClient::EndLogin(UObject* InWorldContext)
{
}

UEpicCMSImage* UPictureInPictureClient::GetAvatarImage()
{
	return nullptr;
}

const PictureInPictureAuthState UPictureInPictureClient::GetLoginState()
{
	return PictureInPictureAuthState();
}

UTexture2DDynamic* UPictureInPictureClient::GetQRCodeTexture()
{
	return nullptr;
}

bool UPictureInPictureClient::IsLoggedIn()
{
	return false;
}

void UPictureInPictureClient::Logout()
{
}
